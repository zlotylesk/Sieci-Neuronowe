#include "Model McCullocha-Pittsa.h"

void SNE_01(){
    cout << "Wybrales zadanie nr 1." << endl;
    cout << "----------------------" << endl;
    cout << "Model McCullocha-Pittsa" << endl;
}

//static void Gate(string gateName, List<double> w)
//{
//    double y = 0.0;
//    if (gateName == "NOT")
//    {
//        double[] u1 = new double[2] { 0, 1 };
//            double[] u2 = new double[2] { 1, 1 };
//
//            List<double[]> u = new List<double[]>() { u1, u2 };
//
//            cout << "u1\ty\tw[i] * u[i]" << endl;
//            for (int i = 0; i < u.Count; i++)
//            {
//                for (int j = 0; j < 2; j++)
//                {
//                    y += w[j] * u[i][j];
//                }
//                if (y >= 0)
//                    cout << u[i][0] + "\t" + 1.0 + "\t" + y << endl;
//                else
//                    cout << u[i][0] + "\t" + 0.0 + "\t" + y << endl;
//                y = 0.0;
//            }
//        };
//
//            if (gateName == "AND" || gateName == "NAND" || gateName == "OR")
//            {
//                double[] u1 = new double[3] { 0, 0, 1 };
//                    double[] u2 = new double[3] { 0, 1, 1 };
//                    double[] u3 = new double[3] { 1, 0, 1 };
//                    double[] u4 = new double[3] { 1, 1, 1 };
//
//                    List<double[]> u = new List<double[]>() { u1, u2, u3, u4 };
//
//                    cout << "u1\tu2\ty\tw[i] * u[i]" << endl;
//                    for (int i = 0; i < u.Count; i++)
//                    {
//                        for (int j = 0; j < 3; j++)
//                        {
//                            y += w[j] * u[i][j];
//                        }
//                        if (y >= 0)
//                            cout << u[i][0] + "\t" + u[i][1] + "\t" + 1.0 + "\t" + y << endl;
//                        else
//                            cout << u[i][0] + "\t" + u[i][1] + "\t" + 0.0 + "\t" + y << endl;
//                        y = 0.0;
//                    }
//                };
//                };
//
//int main()
//{
//
//    List<double> weights = new List<double>();
//
//    //NOT
//    cout<< "NOT:" << endl;
//    cout << "*********" << endl;
//    weights.Add(-0.5);
//    weights.Add(0.33);
//    Gate("NOT", weights);
//    weights.Clear();
//
//    cout << endl;
//
//    //AND
//    cout << "AND:" << endl;
//    cout << ("*****************") << endl;
//    weights.Add(0.33);
//    weights.Add(0.33);
//    weights.Add(-0.5);
//    Gate("AND", weights);
//    weights.Clear();
//
//    cout << endl;
//
//    //NAND
//    cout << "NAND:" << endl;
//    cout << ("*****************") << endl;
//    weights.Add(-0.33);
//    weights.Add(-0.33);
//    weights.Add(0.5);
//    Gate("NAND", weights);
//    weights.Clear();
//
//    cout << endl;
//
//    //OR
//    cout << "OR:" << endl;
//    cout << "*****************" << endl;
//    weights.Add(0.33);
//    weights.Add(0.33);
//    weights.Add(-0.33);
//    Gate("OR", weights);
//    weights.Clear();
//
//    return 0;
//}