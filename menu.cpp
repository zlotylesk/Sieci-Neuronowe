#include "header.h"
void menu(){
    short int wybor;
    cout << "Wybierz interesujące Cię zadanie:" << endl;
    cout << "(1) Zadanie 1." << endl;
    cout << "(2) Zadanie 2." << endl;
    cout << "(3) Zadanie 3." << endl;
    cout << "(4) Zadanie 4." << endl;
    cout << "(5) Zadanie 5." << endl;
    cout << "(6) Zadanie 6." << endl;
    cout << "(7) Zadanie 7." << endl;
    cout << "(8) Zadanie 8." << endl;
    cout << "Dokonaj wyboru:" << endl;
    cin >> wybor;
    switch (wybor){
        case 1:
            cout << "Wybrales zadanie nr 1." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        case 2:
            cout << "Wybrales zadanie nr 2." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        case 3:
            cout << "Wybrales zadanie nr 3." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        case 4:
            cout << "Wybrales zadanie nr 4." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        case 5:
            cout << "Wybrales zadanie nr 5." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        case 6:
            cout << "Wybrales zadanie nr 6." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        case 7:
            cout << "Wybrales zadanie nr 7." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        case 8:
            cout << "Wybrales zadanie nr 8." << endl;
            cout << "----------------------" << endl;
            cout << "Temat zadania" << endl;
            break;
        default:
            cout << "Dokonano niepoprawnego wyboru" << endl;
            break;
    }
}