// 2lab_Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Header.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << endl;
        exit(1);
    }

    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);

    cout << "Start" << endl;

    Container* Head = new Container(); //Создание нового контейнера

    Init_Container(Head); //Инициализация контейнера

    In_Container(Head, ifst); //Ввод элементов в контейнер

    ofst << "Filled and sorted container. " << endl;

    Sort(Head); //Сортировка контейнера

    Out_Container(Head, ofst); //Вывод контейнера

    Clear_Container(Head); //Очистка контейнера

    ofst << "Empty container. " << endl;

    Out_Container(Head, ofst); //Вывод контейнера

    cout << "Stop" << endl;
    system("pause");
    return 0;
}
