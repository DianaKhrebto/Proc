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
    SHRUB //Кустарник
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

//Структура "растение"
struct Plant {
    Key K; //Идентификатор растения
    string Name; //Название растения

    //Объект растения
    union {
        Tree T;
        Shrub S;
    };
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

//Функция ввода растения
Plant* In_Plant(ifstream& ifst);

//Функция вывода растения
void Out_Plant(Plant* P, ofstream& ofst);

void In_Tree(Tree& T, ifstream& ifst);

void Out_Tree(string Name, Tree& T, ofstream& ofst);

void In_Shrub(Shrub& S, ifstream& ifst);

void Out_Shrub(string Name, Shrub& S, ofstream& ofst);

#endif // HEADER_H