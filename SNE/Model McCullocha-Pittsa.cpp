#include "Model McCullocha-Pittsa.h"

void introSNE01(){
    cout << "Wybrales zadanie nr 1." << endl;
    cout << "----------------------" << endl;
    cout << "Model McCullocha-Pittsa" << endl;
}

void perform(vector<double> weightVector) {
    vector<vector<double> > values;
    vector<double> tmp;

    tmp.push_back(0.0);
    tmp.push_back(0.0);
    tmp.push_back(1.0);
    values.push_back(tmp);
    tmp.clear();

    tmp.push_back(0.0);
    tmp.push_back(1.0);
    tmp.push_back(1.0);
    values.push_back(tmp);
    tmp.clear();

    tmp.push_back(1.0);
    tmp.push_back(0.0);
    tmp.push_back(1.0);
    values.push_back(tmp);
    tmp.clear();

    tmp.push_back(1.0);
    tmp.push_back(1.0);
    tmp.push_back(1.0);
    values.push_back(tmp);
    tmp.clear();

    for (int i=0; i<4; i++) {
        printf("%f %f ", values[i][0], values[i][1]);
        if (weightVector[0] * values[i][0] + weightVector[1] * values[i][1] + weightVector[2] * values[i][2] >= 0.0) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

}

int SNE01(){
    introSNE01();

    vector<double> notVal;
    vector<double> andVal;
    vector<double> nandVal;
    vector<double> orVal;

    notVal.push_back(-0.5);
    notVal.push_back(0.33);

    andVal.push_back(0.33);
    andVal.push_back(0.33);
    andVal.push_back(-0.5);

    nandVal.push_back(-0.33);
    nandVal.push_back(-0.33);
    nandVal.push_back(0.5);

    orVal.push_back(0.33);
    orVal.push_back(0.33);
    orVal.push_back(-0.33);

    printf("NOT\n\n");
    perform(notVal);

    printf("AND\n\n");
    perform(andVal);

    printf("NAND\n\n");
    perform(nandVal);

    printf("OR\n\n");
    perform(orVal);
    
    
    system("PAUSE");
    return 0;
};

