#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<double> getClearVector(double val) {
	
	vector<double> tmp;
	for (int i = 0; i<25; i++) {
		tmp.push_back(val);
	}
	
	return tmp;
	
}

vector<double> createZvector(vector<int> input) {
	vector<double> output;
	int inputLength;

	output = getClearVector(-1.0);
	inputLength = input.size();
	
	for (int i=0; i<inputLength; i++) {
		output[input[i]] = 1.0;
	}

	return output;
	
}

vector<vector<double> > createWvector(vector<double> w, vector<double> u) {
	vector<vector<double> > output;

	getClearVector(-1.0);
	
	for (int i=0; i<25; i++) {
		output.push_back(getClearVector(-1.0));
		for (int j=0; j<25; j++) {
			output[i][j] = 1.0/25.0 * (w[i] * w[j] + u[i] * u[j]);
		}
		
	}

	return output;
	
}
vector<double> calculateSGN(vector<double> vecU) {
	for (int i=0; i<25; i++) {
		if(vecU[i] >= 0.0) {
			vecU[i] = 1.0;
		} else {
			vecU[i] = -1.0;
		}
		
	}
	return vecU;
}

vector<double> calculateF(vector<vector<double> > vecW, vector<double> vecU) {
	vector<double> output;
	double tmpVal;
	for (int i=0; i<25; i++) {
		tmpVal = 0.0;
		for (int j=0; j<25; j++) {
			tmpVal += vecW[i][j] * vecU[j];
			
		}		
		output.push_back(tmpVal);
		
	}
	output = calculateSGN(output);
	return output;
}

void printVector(vector<double> vec) {
	for (int i=0; i<25; i++) {
		if (vec[i] == -1.0) {
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
	vector<int> positions;
	vector<double> vecZ1;
	vector<double> vecZ2;
	vector<double> vecU;
	vector<double> result;
	vector<vector<double> > vecW;
	
	//Creating Z1 and Z2 vectors
	positions.push_back(6);
	positions.push_back(7);
	positions.push_back(8);
	positions.push_back(11);
	positions.push_back(13);
	positions.push_back(16);
	positions.push_back(17);
	positions.push_back(18);
	
	vecZ1 = createZvector(positions);
	
	positions.clear();
	
	positions.push_back(6);
	positions.push_back(7);
	positions.push_back(12);
	positions.push_back(17);
	
	vecZ2 = createZvector(positions);
	vecW = createWvector(vecZ1, vecZ2);
	
	
	printf("\n\nz0\n\n");
	result = calculateF(vecW, vecZ1);
	
	printVector(result);
	
	printf("\n\nz1\n\n");
	result = calculateF(vecW, vecZ2);
	
	printVector(result);
	
	printf("\n\nzaburzone z0\n\n");
	positions.clear();
	
	positions.push_back(2);
	positions.push_back(3);
	positions.push_back(4);
	positions.push_back(6);
	positions.push_back(8);
	positions.push_back(11);
	positions.push_back(13);
	positions.push_back(16);
	positions.push_back(17);
	positions.push_back(18);
	
	vecU = createZvector(positions);
	result = calculateF(vecW, vecU);
	
	printVector(result);
	
	printf("\n\nzaburzone z1\n\n");
	positions.clear();
	
	positions.push_back(2);
	positions.push_back(7);
	positions.push_back(12);
	positions.push_back(17);
	positions.push_back(22);
	
	vecU = createZvector(positions);
	result = calculateF(vecW, vecU);
	
	printVector(result);

	
	return 0;
}
