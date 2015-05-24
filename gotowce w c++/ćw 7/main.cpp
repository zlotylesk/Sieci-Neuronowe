#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#include <conio.h>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double tZero = 1.0;
double temperature = 1.0;


double calculateTheta(vector<double> vec) {
	double sum = 0.0;
	for (int i =0; i<25; i++) {
		sum+= vec[i];
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

double calculateFuit (double u) {
	double e = 2.71828;
	return 1.0 / (1.0 + pow(e, -1.0 * (u / temperature)));
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
	double uit = 0.0, fuit;
	srand(time(NULL));
	for (int i=0; i<25; i++) {
		uit = 0.0;
		for (int j=0; j<25; j++) {
			uit+= 2*vectorC[i][j] * prev[j];
		}
		uit -= calculateTheta(vectorC[i]);
		fuit = calculateFuit(uit);
	//	cout <<":fuit:" << fuit << endl;
		if (fuit > (double)((rand() % 11) / 10.0)) {
			vec.push_back(1.0);
		} else {
			vec.push_back(0.0);
		}
	/*	if (uit>0) {
			vec.push_back(1.0);
		} else if (uit == 0) {
			vec.push_back(prev[i]);
		} else {
			vec.push_back(0.0);
		}*/
		
		
	}

	return vec;
}

double generateNextTemperature (double time) {
	return tZero / (1.0+log((double)time + 1.0));
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




int main(int argc, char** argv) {
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

	
	vector<double> vectorX = generateRandomVector();
	printVector(vectorX);
	double time = 0.0;
	while (getch() != '\x1B') {
		temperature = generateNextTemperature(time);
		cout << "T(" << time << ") = " << temperature << endl;
		time += 1.0;
		printf("\n");
		vectorX = generateNextVector(vectorX, vectorC);
		printVector(vectorX);
		printf("\n");
	}
	
	
	
	
	
	
	
	return 0;
}
