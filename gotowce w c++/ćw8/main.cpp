#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

double E(int d[10][10], int S[10]) {
	double ES = 0;
	int i = 0;
	while (i < 9) {
		ES += d[S[i]][S[i + 1]];
		i++;
	}
	ES += d[S[0]][S[9]];
	return ES;
}

int* nextRandomS(int S[10]) {
	int* nextS = new int[10];
	int k = rand() % 10, l = rand() % 10;
	
	while (k == l) {
		k = rand() % 10;
	}

	for (int i = 0; i < 10; i++) {
		nextS[i] = S[i];
	}

	int temp = nextS[k];
	nextS[k] = nextS[l];
	nextS[l] = temp;

	return nextS;
}

double delta_E(int S2[10], int S1[10], int d[10][10]) {
	return E(d, S2) - E(d, S1);
}

bool isAccepted(float delta_E, float T) {
	if (delta_E < 0 || ((rand() % 100) + 1) * 0.01 < pow(2.71828, -(delta_E/T))) {
		return true;
	}
	return false;
}

void print(int arr[10]) {
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {

	// odleg³oœæ pomiêdzy miastami
	int d[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((i == 0 && j == 9) || (i == 9 && j == 0)) {
				d[i][j] = 1;
			} 
			else {
				if (i - j < 0) {
					d[i][j] = j - i;
				} 
				else {
					d[i][j] = i - j;
				}
			}
		}
	}

	srand((unsigned int)time(NULL));
	int S[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// silnia(10) = 3628800
	int perm = (rand() % 3628800) + 1;
	int i = 0;

	while (i < perm) {
		next_permutation(S, S + 10);
		i++;
	}

	double ES = E(d, S);
	double T0 = 100;
	double T = 100;
	double t = 0;
	int M = 10;
	int L = 3;
	int acceptedSolutions = 0;

	// algorytm symolowanego wy¿arzania - TSP

	// nie spe³niony warunek zatrzymania
	while (acceptedSolutions < L) {

		int newSolutions = 0;

		// nie osi¹gniêty stan równowagi
		for (int newSolutions = 1; newSolutions <= 10; newSolutions++) {

			int* S_prim = nextRandomS(S);
			double delta = delta_E(S_prim, S, d);

			if (isAccepted(delta, T)) {
				for (int i = 0; i < 10; i++) {
					S[i] = S_prim[i];
				}
				acceptedSolutions++;
			}
		}
		T = T0 / (1 + log(++t));
	}
	
	cout << "Zadanie 1" << endl;
	cout << "S = ";
	print(S);
	cout << "ES = " << E(d, S) << endl << endl;


	// zadanie 2

	int d2[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i < j) {
				d2[i][j] = pow(i+1, 3) + pow(j+1, 3) - (pow(i+1, 2) * (j+1)) - (pow(j+1, 2) * (i+1)) - (4 * pow(j+1, 2)) + (4 * (i+1)) + (4 * (j+1)) + 1;
			} 
			else if (i > j) {
				d[i][j] = d[j][i];
			} 
			else if ((i + 1 == 1 && j + 1 == 2) || (i + 1 == 9 && j + 1 == 10)) {
				d[i][j] = 1;
			}
		}
	}

	
	T = 10;
	t = 0;
	acceptedSolutions = 0;
	
	for (int i = 0; i < 10; i++) {
		S[i] = i + 1;
	}

	perm = (rand() % 3628800) + 1;
	i = 0;

	while (i < perm) {
		next_permutation(S, S + 10);
		i++;
	}

	// nie spe³niony warunek zatrzymania
	while (acceptedSolutions < L) {

		// nie osi¹gniêty stan równowagi
		for (int newSolutions = 1; newSolutions <= 10; newSolutions++) {

			int* S_prim = nextRandomS(S);
			double delta = delta_E(S_prim, S, d2);

			if (isAccepted(delta, T)) {
				for (int i = 0; i < 10; i++) {
					S[i] = S_prim[i];
				}
				acceptedSolutions++;
			}
		}
		T = T0 / (1 + log(++t));
	}

	cout << "Zadanie 2" << endl;
	cout << "S = ";
	print(S);
	cout << "ES = " << E(d, S) << endl;

	system("PAUSE");
	return 0;
}
