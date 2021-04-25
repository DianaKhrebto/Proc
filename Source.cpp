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

        ofst << "Amount of consonant letters in the name of plant = " << Plant_consonant_letters(Head->Cont) << endl << endl;

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

void Sort(Container* Head) {
    if (Head->Len > 1) {
        Container* First = Head;
        Container* Second = Head->Next;

        Container* Temp = new Container;

        while (First->Next && First->Next->Next) {
            while (Second && Second->Next) {
                if (Compare(First->Cont, Second->Cont)) {
                    Temp->Cont = First->Cont;
                    First->Cont = Second->Cont;
                    Second->Cont = Temp->Cont;
                }

                Second = Second->Next;
            }

            First = First->Next;
            Second = First->Next;
        }
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

        string Habitant = "";

        ifst >> Habitant;

        if (Habitant == "Tundra") {
            P->H = TUNDRA;
        }
        else if (Habitant == "Desert") {
            P->H = DESERT;
        }
        else if (Habitant == "Steppe") {
            P->H = STEPPE;
        }
        else if (Habitant == "Taiga") {
            P->H = TAIGA;
        }

        In_Tree(P->T, ifst);
    }
    else if (K == 2) {
        P = new Plant;
        P->K = SHRUB;

        ifst >> P->Name;

        string Habitant = "";

        ifst >> Habitant;

        if (Habitant == "Tundra") {
            P->H = TUNDRA;
        }
        else if (Habitant == "Desert") {
            P->H = DESERT;
        }
        else if (Habitant == "Steppe") {
            P->H = STEPPE;
        }
        else if (Habitant == "Taiga") {
            P->H = TAIGA;
        }

        In_Shrub(P->S, ifst);
    }
    else if (K == 3) {
        P = new Plant;
        P->K = FLOWER;

        ifst >> P->Name;

        In_Flower(P->F, ifst);
    }
    
    return P;
}

void Out_Plant(Plant* P, ofstream& ofst) {
    if (P->K == TREE) {
        Out_Tree(P->Name, P->H, P->T, ofst);
    }
    else if (P->K == SHRUB) {
        Out_Shrub(P->Name, P->H, P->S, ofst);
    }
    else if (P->K == FLOWER) {
        Out_Flower(P->Name, P->F, ofst);
    }
    else {
        ofst << "Incorrect element!" << endl << endl;
    }
}

int Plant_consonant_letters(Plant* P) {
    if (P->K == TREE) {
        return Tree_consonant_letters(P->Name);
    }
    else if (P->K == SHRUB) {
        return Shrub_consonant_letters(P->Name);
    }
    else if (P->K == FLOWER) {
        return Flower_consonant_letters(P->Name);
    }
    else {
        return -1;
    }
}

bool Compare(Plant* First, Plant* Second) {
    return Plant_consonant_letters(First) > Plant_consonant_letters(Second);
}

void In_Tree(Tree& T, ifstream& ifst) {
    ifst >> T.Age;
}

void Out_Tree(string Name, Habitation H, Tree& T, ofstream& ofst) {
    ofst << "It's a tree with name: " << Name << endl;
    ofst << "Tree's age is " << T.Age << endl;
    ofst << "Tree's habitation is " ;

    if (H == TUNDRA) {
        ofst << "Tundra";
    }
    else if (H == DESERT) {
        ofst << "Desert";
    }
    else if (H == STEPPE) {
        ofst << "Steppe";
    }
    else if (H == TAIGA) {
        ofst << "Taiga";
    }

    ofst << endl << endl;
}

int Tree_consonant_letters(string Name) {
    string Constant_letter = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";

    int Amount = 0;

    for (int i = 0; i < Name.length(); i++) {
        for (int j = 0; j < Constant_letter.length(); j++) {
            if (Name[i] == Constant_letter[j]) {
                Amount++;
                break;
            }
        }
    }

    return Amount;
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

void Out_Shrub(string Name, Habitation H, Shrub& S, ofstream& ofst) {
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

    ofst << endl;

    ofst << "Shrub's habitation is ";

    if (H == TUNDRA) {
        ofst << "Tundra";
    }
    else if (H == DESERT) {
        ofst << "Desert";
    }
    else if (H == STEPPE) {
        ofst << "Steppe";
    }
    else if (H == TAIGA) {
        ofst << "Taiga";
    }

    ofst << endl << endl;
}

int Shrub_consonant_letters(string Name) {
    string Constant_letter = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";

    int Amount = 0;

    for (int i = 0; i < Name.length(); i++) {
        for (int j = 0; j < Constant_letter.length(); j++) {
            if (Name[i] == Constant_letter[j]) {
                Amount++;
                break;
            }
        }
    }

    return Amount;
}

void In_Flower(Flower& F, ifstream& ifst) {
    string Type = "";

    ifst >> Type;

    if (Type == "Home") {
        F.T = F.HOME;
    }
    else if (Type == "Garden") {
        F.T = F.GARDEN;
    }
    else if (Type == "Wild") {
        F.T = F.WILD;
    }
}

void Out_Flower(string Name, Flower& F, ofstream& ofst) {
    ofst << "It's a flower with name: " << Name << endl;
    ofst << "Flower's type is ";

    if (F.T == F.HOME) {
        ofst << "Home";
    }
    else if (F.T == F.GARDEN) {
        ofst << "Garden";
    }
    else if (F.T == F.WILD) {
        ofst << "Wild";
    }

    ofst << endl << endl;
}

int Flower_consonant_letters(string Name) {
    string Constant_letter = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";

    int Amount = 0;

    for (int i = 0; i < Name.length(); i++) {
        for (int j = 0; j < Constant_letter.length(); j++) {
            if (Name[i] == Constant_letter[j]) {
                Amount++;
                break;
            }
        }
    }

    return Amount;
}