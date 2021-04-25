#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//������������� ��������
enum Key {
    TREE, //������
    SHRUB, //���������
    FLOWER //������
};

//����� ��������
enum Habitation {
    TUNDRA, //������
    DESERT, //�������
    STEPPE, //�����
    TAIGA //�����
};

//��������� "������"
struct Tree {
    long int Age; //������� ������
};

//��������� "���������"
struct Shrub {
    //����� ��������
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

    Month M; //����� ��������
};

//��������� "������"
struct Flower {
    //��� ������
    enum Type {
        HOME,
        GARDEN,
        WILD
    };

    Type T; //��� ������
};

//��������� "��������"
struct Plant {
    Key K; //������������� ��������
    string Name; //�������� ��������

    //������ ��������
    union {
        Tree T;
        Shrub S;
        Flower F;
    };

    Habitation H;
};

//��������� "���������"
struct Container {
    Container* Next; //��������� �� ��������� ������� ����������
    Plant* Cont; //��������� �� ��������
    int Len; //���������� ����������
};

//������� ������������� ����������
void Init_Container(Container* Head);

//������� ����� ��������� � ���������
void In_Container(Container* Head, ifstream& ifst);

//������� ������ ����������
void Out_Container(Container* Head, ofstream& ofst);

//������� ������� ����������
void Clear_Container(Container* Head);

//������� ������ ������ ��������
void Out_Only_Tree(Container* Head, ofstream& ofst);

//������� ���������� ����������
void Sort(Container* Head);

//������� ����� ��������
Plant* In_Plant(ifstream& ifst);

//������� ������ ��������
void Out_Plant(Plant* P, ofstream& ofst);

//������� �������� ����� ��������� ���� � �������� ��������
int Plant_consonant_letters(Plant* P);

//������� ��������� ����� ��������� ���� � ��������� �������� 
bool Compare(Plant* First, Plant* Second);

//������� ����� ������
void In_Tree(Tree& T, ifstream& ifst);

//������� ������ ������
void Out_Tree(string Name, Habitation H, Tree& T, ofstream& ofst);

//������� �������� ����� ��������� ���� � �������� ������
int Tree_consonant_letters(string Name);

//������� ����� ����������
void In_Shrub(Shrub& S, ifstream& ifst);

//������� ������ ����������
void Out_Shrub(string Name, Habitation H, Shrub& S, ofstream& ofst);

//������� �������� ����� ��������� ���� � �������� ����������
int Shrub_consonant_letters(string Name);

//������� ����� ������
void In_Flower(Flower& F, ifstream& ifst);

//������� ������ ������
void Out_Flower(string Name, Habitation H, Flower& F, ofstream& ofst);

//������� �������� ����� ��������� ���� � �������� ������
int Flower_consonant_letters(string Name);

#endif // HEADER_H