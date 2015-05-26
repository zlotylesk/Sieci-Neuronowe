#include "Metoda gradientu.h"
void introSNE04(){
    cout << "Wybrales zadanie nr 4." << endl;
    cout << "----------------------" << endl;
    cout << "Metoda gradientu" << endl;
}
double cVal = 0.01;
double epsVal = 0.00000001;

double calcFirstX (vector<double> vec) {
    return 4.0*vec[0] - 2.0* vec[1] - 2.0;
}
double calcFirstY (vector<double> vec) {
    return 4.0*vec[1] - 2.0* vec[0] - 2.0*vec[2];
}
double calcFirstZ (vector<double> vec) {
    return 2.0* vec[2] - 2.0*vec[1];
}
double calcSecondX (vector<double> vec) {
    return 12 * pow(vec[0], 3.0) + 12 * pow(vec[0], 2.0) - 24 * vec[0];
}
double calcSecondY (vector<double> vec) {
    return 24 * vec[1] - 24;
}

void gradientFirst (vector<double> input) {
    vector<double> vectorNew;
    bool flag = true;
    double max = 0.0;
    for (int i=0; i<3; i++) {
        vectorNew.push_back(0.0);
    }

    while (flag) {
        vectorNew[0] = input[0] - 	cVal * calcFirstX(input);
        vectorNew[1] = input[1] - 	cVal * calcFirstY(input);
        vectorNew[2] = input[2] - 	cVal * calcFirstZ(input);
        max = 0.0;
        for (int i=0; i<3; i++) {

            if (fabs(vectorNew[i] - input[i]) > max) {
                max = fabs(vectorNew[i] - input[i]);
            }
        }
        if (max < epsVal) {
            printf("punkt: %f, %f, %f\nwartosc: %f", vectorNew[0], vectorNew[1], vectorNew[2], 2 * pow(vectorNew[0], 2.0) + 2 * pow(vectorNew[1], 2.0) + vectorNew[2]*vectorNew[2] - 2 * vectorNew[0] * vectorNew[1] - 2 * vectorNew[2] *vectorNew[1] - 2* vectorNew[0] + 3);
            flag = false;
        }
        input = vectorNew;

    }
}

void gradientSecond (vector<double> input) {
    vector<double> vectorNew;
    bool flag = true;
    double max = 0.0;
    for (int i=0; i<2; i++) {
        vectorNew.push_back(0.0);
    }
    while (flag) {
        vectorNew[0] = input[0] - 	cVal * calcSecondX(input);
        vectorNew[1] = input[1] - 	cVal * calcSecondY(input);

        max = 0.0;
        for (int i=0; i<2; i++) {
            if (fabs(vectorNew[i] - input[i]) > max) {
                max = fabs(vectorNew[i] - input[i]);
            }
        }
        if (max < epsVal) {
            printf("punkt: %lf, %lf\nwartosc: %lf", vectorNew[0], vectorNew[1], vectorNew[0]*vectorNew[0]*vectorNew[0]*vectorNew[0] * 3 + 4* vectorNew[0]*vectorNew[0]*vectorNew[0] - 12 * vectorNew[0]*vectorNew[0] + 12*vectorNew[1] * vectorNew[1] - 24 * vectorNew[1]);
            flag = false;
        }
        input = vectorNew;

    }
}

int SNE04(){
    introSNE04();
    srand(time(NULL));

    vector<double> vectorFirst;
    vectorFirst.push_back((double)rand());
    vectorFirst.push_back((double)rand());
    vectorFirst.push_back((double)rand());
    gradientFirst(vectorFirst);
    cout << endl << endl <<endl;

    vector<double> vectorSecond;
    vectorSecond.push_back(1.0);
    vectorSecond.push_back(1.0);
    gradientSecond(vectorSecond);
    
	system("PAUSE");
    return 0;
};

