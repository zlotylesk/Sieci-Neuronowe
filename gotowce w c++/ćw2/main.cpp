#include <iostream>
#include <stdio.h>
#include <vector>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
vector<double> getClearVector(double val) {
	
	vector<double> tmp;
	for (int i = 0; i<26; i++) {
		tmp.push_back(val);
	}
	
	return tmp;
	
}
vector<vector<double> > createInitialVectors() {
	vector<vector<double> > vectorsBase;
	vector<double> tmp;
	
	//U1
	tmp = getClearVector(0.0);
	tmp[6] = 1.0;
	tmp[7] = 1.0;
	tmp[12] = 1.0;
	tmp[17] = 1.0;
	tmp[22] = 1.0;
	tmp[25] = 1.0;
	vectorsBase.push_back(tmp);
	
	//U2
	tmp = getClearVector(0.0);
	tmp[1] = 1.0;
	tmp[2] = 1.0;
	tmp[7] = 1.0;
	tmp[12] = 1.0;
	tmp[25] = 1.0;
	vectorsBase.push_back(tmp);
	
	//U3
	tmp = getClearVector(0.0);
	tmp[5] = 1.0;
	tmp[6] = 1.0;
	tmp[11] = 1.0;
	tmp[16] = 1.0;
	tmp[21] = 1.0;
	tmp[25] = 1.0;
	vectorsBase.push_back(tmp);
	
	//U4
	tmp = getClearVector(0.0);
	tmp[6] = 1.0;
	tmp[7] = 1.0;
	tmp[8] = 1.0;
	tmp[11] = 1.0;
	tmp[13] = 1.0;
	tmp[16] = 1.0;
	tmp[17] = 1.0;
	tmp[18] = 1.0;
	vectorsBase.push_back(tmp);
	
	//U5
	tmp = getClearVector(0.0);
	tmp[11] = 1.0;
	tmp[12] = 1.0;
	tmp[13] = 1.0;
	tmp[15] = 1.0;
	tmp[17] = 1.0;
	tmp[20] = 1.0;
	tmp[21] = 1.0;
	tmp[22] = 1.0;
	tmp[25] = 1.0;
	vectorsBase.push_back(tmp);
	
	return vectorsBase;
	
}

double getScalarSum(vector<double> w, vector<double> u) {
	double output = 0.0;
	
	for (int i=0; i<26; i++) {
		output += w[i] * u[i];	
	}
	
	if (output >= 0){
		return 1.0;
	} else {
		return 0.0;
	}
	
	
}


int main(int argc, char** argv) {
	int time;
	double counter;
	
	double c;
	double zt;
	double scalarSum;
	
	
	vector<vector <double> > uVectors;
	vector<double> wVector;
	
	uVectors = createInitialVectors();
	wVector = getClearVector(1.0);
	
	//start of the algorithm
	time = 1;
	counter = 0.0;
	c = 1.0;
	
	while (counter != 5.0) {
		if (time%5+1 <= 3) {
			zt = 1.0;
		} else {
			zt = 0.0;
		}
		scalarSum = getScalarSum(wVector, uVectors[time%5]);
		for (int i = 0; i<26; i++) {
			wVector[i] = wVector[i] + c * (zt - scalarSum) * uVectors[time%5][i];
		}
		time++;
		if (scalarSum == zt) {
			counter += 1.0;
		} else {
			counter = 0.0;
		}
	}
	
	printf("time = %d\n", time);
	for (int i=0; i<26; i++) {
		printf("%d %lf\n", i,wVector[i]);	
	}
	
	return 0;
}
