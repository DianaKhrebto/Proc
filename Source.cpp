#include "Header.h"

void Init_Container(Container* Head) {
    Head->Cont = NULL;
    Head->Next = NULL;
    Head->Len = 0;
}

void In_Container(Container* Head, ifstream& ifst) {
    Container* Temp_Head = Head;
    int Len = 0;

    while (!ifst.eof()) {
        if ((Head->Cont = In_Plant(ifst))) {
            Head->Next = new Container();
            
            Head = Head->Next;
            Len++;
        }
    }

    while (Temp_Head->Cont != NULL) {
        Temp_Head->Len = Len;
        Temp_Head = Temp_Head->Next;
    }
}

void Out_Container(Container* Head, ofstream& ofst) {
    ofst << "Container contains " << Head->Len
        << " elements." << endl << endl;

    for (int i = 0; i < Head->Len; i++) {
        ofst << i << ": ";
        Out_Plant(Head->Cont, ofst);
        Head = Head->Next;
    }
}

void Clear_Container(Container* Head) {
    for (int i = 0; i < Head->Len; i++) {
        Head->Len = 0;
        free(Head->Cont);
        Head = Head->Next;
    }
}

Plant* In_Plant(ifstream& ifst) {
    Plant* P = NULL;
    int K;

    ifst >> K;
    
    if (K == 1) {
        P = new Plant;
        P->K = TREE;
        
        ifst >> P->Name;

        In_Tree(P->T, ifst);
    }
    else if (K == 2) {
        P = new Plant;
        P->K = SHRUB;

        ifst >> P->Name;

        In_Shrub(P->S, ifst);
    }
    
    return P;
}

void Out_Plant(Plant* P, ofstream& ofst) {
    if (P->K == TREE) {
        Out_Tree(P->Name, P->T, ofst);
    }
    else if (P->K == SHRUB) {
        Out_Shrub(P->Name, P->S, ofst);
    }
    else {
        ofst << "Incorrect element!" << endl << endl;
    }
}

void In_Tree(Tree& T, ifstream& ifst) {
    ifst >> T.Age;
}

void Out_Tree(string Name, Tree& T, ofstream& ofst) {
    ofst << "It's a tree with name: " << Name << endl;
    ofst << "Tree's age is " << T.Age << endl << endl;
}

void In_Shrub(Shrub& S, ifstream& ifst) {
    string Month = "";

    ifst >> Month;

    if (Month == "Jenuary") {
        S.M = S.JENUARY;
    }
    else if (Month == "February") {
        S.M = S.FEBRUARY;
    }
    else if (Month == "March") {
        S.M = S.MARCH;
    }
    else if (Month == "April") {
        S.M = S.APRIL;
    }
    else if (Month == "May") {
        S.M = S.MAY;
    }
    else if (Month == "June") {
        S.M = S.JUNE;
    }
    else if (Month == "July") {
        S.M = S.JULY;
    }
    else if (Month == "August") {
        S.M = S.AUGUST;
    }
    else if (Month == "September") {
        S.M = S.SEPTEMBER;
    }
    else if (Month == "October") {
        S.M = S.OCTOBER;
    }
    else if (Month == "November") {
        S.M = S.NOVEMBER;
    }
    else if (Month == "December") {
        S.M = S.DECEMBER;
    }
}

void Out_Shrub(string Name, Shrub& S, ofstream& ofst) {
    ofst << "It's a shrub with name: " << Name << endl;
    ofst << "Shrub's flowering month is ";

    if (S.M == S.JENUARY) {
        ofst << "Jenuary";
    }
    else if (S.M == S.FEBRUARY) {
        ofst << "February";
    }
    else if (S.M == S.MARCH) {
        ofst << "March";
    }
    else if (S.M == S.APRIL) {
        ofst << "April";
    }
    else if (S.M == S.MAY) {
        ofst << "May";
    }
    else if (S.M == S.JUNE) {
        ofst << "June";
    }
    else if (S.M == S.JULY) {
        ofst << "July";
    }
    else if (S.M == S.AUGUST) {
        ofst << "August";
    }
    else if (S.M == S.SEPTEMBER) {
        ofst << "September";
    }
    else if (S.M == S.OCTOBER) {
        ofst << "October";
    }
    else if (S.M == S.NOVEMBER) {
        ofst << "November";
    }
    else if (S.M == S.DECEMBER) {
        ofst << "December";
    }

    ofst << endl << endl;
}