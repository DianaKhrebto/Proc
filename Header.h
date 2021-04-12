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

//��������� "��������"
struct Plant {
    Key K; //������������� ��������
    string Name; //�������� ��������

    //������ ��������
    union {
        Tree T;
        Shrub S;
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

//������� ����� ��������
Plant* In_Plant(ifstream& ifst);

//������� ������ ��������
void Out_Plant(Plant* P, ofstream& ofst);

void In_Tree(Tree& T, ifstream& ifst);

void Out_Tree(string Name, Habitation H, Tree& T, ofstream& ofst);

void In_Shrub(Shrub& S, ifstream& ifst);

void Out_Shrub(string Name, Habitation H, Shrub& S, ofstream& ofst);

#endif // HEADER_H