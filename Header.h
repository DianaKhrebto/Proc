#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Иднетификатор растения
enum Key {
    TREE, //Дерево
    SHRUB, //Кустарник
    FLOWER //Цветок
};

//Среда обитания
enum Habitation {
    TUNDRA, //Тундра
    DESERT, //Пустыня
    STEPPE, //Степь
    TAIGA //Тайга
};

//Структура "дерево"
struct Tree {
    long int Age; //Возраст дерева
};

//Структура "кустарник"
struct Shrub {
    //Месяц цветения
    enum Month {
        JENUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };

    Month M; //Месяц цветения
};

//Структура "цветок"
struct Flower {
    //Тип цветка
    enum Type {
        HOME,
        GARDEN,
        WILD
    };

    Type T; //Тип цветка
};

//Структура "растение"
struct Plant {
    Key K; //Идентификатор растения
    string Name; //Название растения

    //Объект растения
    union {
        Tree T;
        Shrub S;
        Flower F;
    };

    Habitation H;
};

//Структура "контейнер"
struct Container {
    Container* Next; //Указатель на следующий элемент контейнера
    Plant* Cont; //Указатель на растение
    int Len; //Разменость контейнера
};

//Функция инициализации контейнера
void Init_Container(Container* Head);

//Функция ввода элементов в контейнер
void In_Container(Container* Head, ifstream& ifst);

//Функция вывода контейнера
void Out_Container(Container* Head, ofstream& ofst);

//Функция очистки контейнера
void Clear_Container(Container* Head);

//Функция вывода только деревьев
void Out_Only_Tree(Container* Head, ofstream& ofst);

//Функция сортировки контейнера
void Sort(Container* Head);

//Функция ввода растения
Plant* In_Plant(ifstream& ifst);

//Функция вывода растения
void Out_Plant(Plant* P, ofstream& ofst);

//Функция подсчета числа согласных букв в названии растения
int Plant_consonant_letters(Plant* P);

//Функция сравнения числа согласных букв в названиях растений 
bool Compare(Plant* First, Plant* Second);

//Функция ввода дерева
void In_Tree(Tree& T, ifstream& ifst);

//Функция вывода дерева
void Out_Tree(string Name, Habitation H, Tree& T, ofstream& ofst);

//Функция подсчета числа согласных букв в названии дерева
int Tree_consonant_letters(string Name);

//Функция ввода кустарника
void In_Shrub(Shrub& S, ifstream& ifst);

//Функция вывода кустарника
void Out_Shrub(string Name, Habitation H, Shrub& S, ofstream& ofst);

//Функция подсчета числа согласных букв в названии кустарника
int Shrub_consonant_letters(string Name);

//Функция ввода цветка
void In_Flower(Flower& F, ifstream& ifst);

//Функция вывода цветка
void Out_Flower(string Name, Habitation H, Flower& F, ofstream& ofst);

//Функция подсчета числа согласных букв в названии цветка
int Flower_consonant_letters(string Name);

#endif // HEADER_H