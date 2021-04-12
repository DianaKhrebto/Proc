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
    SHRUB //���������
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

//��������� "��������"
struct Plant {
    Key K; //������������� ��������
    string Name; //�������� ��������

    //������ ��������
    union {
        Tree T;
        Shrub S;
    };
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
void Out_Tree(string Name, Tree& T, ofstream& ofst);

//������� �������� ����� ��������� ���� � �������� ������
int Tree_consonant_letters(string Name);

//������� ����� ����������
void In_Shrub(Shrub& S, ifstream& ifst);

//������� ������ ����������
void Out_Shrub(string Name, Shrub& S, ofstream& ofst);

//������� �������� ����� ��������� ���� � �������� ����������
int Shrub_consonant_letters(string Name);

#endif // HEADER_H