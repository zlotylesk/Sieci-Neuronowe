#include "Sieci Hopfielda.h"
void introSNE06(){
    cout << "Wybrales zadanie nr 6." << endl;
    cout << "----------------------" << endl;
    cout << "Sieci Hopfielda" << endl;
}

double calculateTheta(vector<double> vec) {
    double sum = 0.0;
    for (int i =0; i<25; i++) {
        sum+= vec[i];
    }
    return sum;
}

double calculateTheta2(vector<double> vec, vector<double> vec2) {
    double sum = 0.0;
    for (int i =0; i<25; i++) {
        sum+= vec[i];
        sum+= vec2[i];
    }
    return sum;
}

vector< vector<double> > calculateVectorC(vector<double> vec) {
    vector< vector<double> > output;
    vector<double> tmp;
    for (int i = 0; i<25; i++) {
        tmp.clear();
        for (int j=0; j<25; j++) {
            if (i != j) {
                tmp.push_back((vec[i] - 0.5) * (vec[j] - 0.5));
            } else {
                tmp.push_back(0.0);
            }
        }
        output.push_back(tmp);
    }
    return output;
}

vector<double> generateRandomVector() {
    vector<double> vec;
    srand(time(NULL));

    for (int i =0; i<25; i++) {
        if (rand() % 2 == 0) {
            vec.push_back(1.0);
        } else {
            vec.push_back(0.0);
        }
    }
    return vec;
}
vector<double> generateNextVector(vector<double> prev, vector< vector<double> > vectorC) {
    vector<double> vec;
    double uit = 0.0;
    for (int i=0; i<25; i++) {
        uit = 0.0;
        for (int j=0; j<25; j++) {
            uit+= 2*vectorC[i][j] * prev[j];
        }
        uit -= calculateTheta(vectorC[i]);

        if (uit>0) {
            vec.push_back(1.0);
        } else if (uit == 0) {
            vec.push_back(prev[i]);
        } else {
            vec.push_back(0.0);
        }


    }

    return vec;
}

vector<double> generateNextVector2(vector<double> prev, vector< vector<double> > vectorC, vector< vector<double> > vectorD) {
    vector<double> vec;
    double uit = 0.0;
    for (int i=0; i<25; i++) {
        uit = 0.0;
        for (int j=0; j<25; j++) {
            uit+= 2*(vectorC[i][j]+vectorD[i][j]) * prev[j];
        }
        uit -= calculateTheta2(vectorC[i], vectorD[i]);

        if (uit>0) {
            vec.push_back(1.0);
        } else if (uit == 0) {
            vec.push_back(prev[i]);
        } else {
            vec.push_back(0.0);
        }


    }

    return vec;
}

void printVector(vector<double> vec) {
    for (int i=0; i<25; i++) {
        if (vec[i] == 0.0) {
            printf("[] ");
        } else {
            printf(" * ");
        }

        if (i%5 == 4) {
            printf("\n");
        }
    }
}


int SNE06(){
    introSNE06();

    vector<double> vectorXs;
    for (int i=0; i<25; i++) {
        vectorXs.push_back(0.0);
    }
    vectorXs[6] = 1.0;
    vectorXs[7] = 1.0;
    vectorXs[12] = 1.0;
    vectorXs[17] = 1.0;
    vectorXs[22] = 1.0;

    vector< vector<double> > vectorC = calculateVectorC(vectorXs);

    vector<double> vectorXr;
    for (int i=0; i<25; i++) {
        vectorXr.push_back(0.0);
    }
    vectorXr[1] = 1.0;
    vectorXr[2] = 1.0;
    vectorXr[3] = 1.0;
    vectorXr[6] = 1.0;
    vectorXr[8] = 1.0;
    vectorXr[11] = 1.0;
    vectorXr[13] = 1.0;
    vectorXr[16] = 1.0;
    vectorXr[18] = 1.0;
    vectorXr[21] = 1.0;
    vectorXr[22] = 1.0;
    vectorXr[23] = 1.0;

    vector< vector<double> > vectorD = calculateVectorC(vectorXr);

    vector<double> vectorX = generateRandomVector();
    printVector(vectorX);

    while (getch() != '\x1B') {
        printf("\n");
        vectorX = generateNextVector2(vectorX, vectorC, vectorD);
        printVector(vectorX);
        printf("\n");
    }

	system("PAUSE");
    return 0;
}

