#include "header.h"
#include "Model McCullocha-Pittsa.h"
#include "Perceptron.h"
#include "Model asocjacji.h"
#include "Metoda gradientu.h"
#include "Propagacja wsteczna.h"
#include "Sieci Hopfielda.h"

void menu(){
    short int wybor;
    cout << "Wybierz interesujące Cię zadanie:" << endl;
    cout << "(1) Zadanie 1. Model McCullocha-Pittsa" << endl;
    cout << "(2) Zadanie 2. Perceptron" << endl;
    cout << "(3) Zadanie 3. Model asocjacji" << endl;
    cout << "(4) Zadanie 4. Metoda gradientu" << endl;
    cout << "(5) Zadanie 5. Propagacja wsteczna" << endl;
    cout << "(6) Zadanie 6. Sieci Hopfielda" << endl;
    cout << "(7) Zadanie 7. TBA" << endl;
    cout << "(8) Zadanie 8. TBA" << endl;
    cout << "Dokonaj wyboru:" << endl;
    cin >> wybor;
    switch (wybor){
        case 1:
            SNE01();
            break;
        case 2:
            SNE02();
            break;
        case 3:
            SNE03();
            break;
        case 4:
            SNE04();
            break;
        case 5:
            SNE05();
            break;
        case 6:
            SNE06();
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