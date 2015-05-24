using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SNE_03
{
    class Program
    {
        static void Intro()
        {
            Console.WriteLine("Wprowadzenie do teorii sieci neuronowych - ćwiczenia.");
            Console.WriteLine("DSNE - Ćwiczenie 3.");
            Console.WriteLine("# Model asocjacji");
            Console.WriteLine("*****************************************************");
            Console.WriteLine();
        }

        static void WindowSize()
        {
            Console.SetWindowSize(Math.Min(110, Console.LargestWindowWidth), Math.Min(40, Console.LargestWindowHeight));
        }

        // Set all values to -1.0 for vector
        static double[] getClearVector(double value)
        {
            double[] vector = new double[25];
            for (int i = 0; i < 25; i++)
            {
                vector[i] = value;
            }
            return vector;
        }

        // Prepare z0 vector; filling up values in z0 vector
        static double[] prepareZ0(string type)
        {
            double[] z0 = new double[25];
            z0 = getClearVector(-1.0);

            if (type == "normal")
            {
                z0[6] = 1.0;
                z0[7] = 1.0;
                z0[8] = 1.0;
                z0[11] = 1.0;
                z0[13] = 1.0;
                z0[16] = 1.0;
                z0[17] = 1.0;
                z0[18] = 1.0;
            }

            if (type == "disturbed")
            {
                z0[1] = 1.0;
                z0[2] = 1.0;
                z0[3] = 1.0;
                z0[6] = 1.0;
                z0[8] = 1.0;
                z0[11] = 1.0;
                z0[13] = 1.0;
                z0[16] = 1.0;
                z0[17] = 1.0;
                z0[18] = 1.0;
            }

            return z0;
        }

        // Prepare z1 vector; filling up values in z1 vector
        static double[] prepareZ1(string type)
        {
            double[] z1 = new double[25];
            z1 = getClearVector(-1.0);

            if (type == "normal")
            {
                z1[6] = 1.0;
                z1[7] = 1.0;
                z1[12] = 1.0;
                z1[17] = 1.0;
            }

            if (type == "disturbed")
            {
                z1[2] = 1.0;
                z1[7] = 1.0;
                z1[12] = 1.0;
                z1[17] = 1.0;
                z1[22] = 1.0;
            }

            return z1;
        }

        // Calculate W matrix
        static double[][] calculateW(double[] z0, double[] z1)
        {
            // Prepare W matrix
            double[][] W = new double[25][];
            for (int i = 0; i < 25; i++)
            {
                W[i] = new double[25];
            }

            // Filling up W matrix
            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    W[i][j] = 1.0 / 25.0 * (z0[i] * z0[j] + z1[i] * z1[j]);
                }
            }

            return W;
        }

        // Calculate SGN function on vector x
        static double[] calculateSGN(double[] x)
        {
            for (int i = 0; i < 25; i++)
            {
                if (x[i] >= 0)
                {
                    x[i] = 1.0;
                }
                else 
                {
                    x[i] = -1.0;
                }
            }

            return x;
        }

        // (Calculate F function on u vector) == y
        static double[] calculateF(double[][] W, double[] u)
        {
            double[] y = new double[25];
            double yValue = 0.0;

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    yValue += W[i][j] * u[j];
                }
                y[i] = yValue;
                yValue = 0;
            }
            y = calculateSGN(y);
            return y;
        }

        static void displayResults(double[] vector)
        {
            for (int i = 0; i < 25; i++)
            {
                if (vector[i] == -1.0)
                {
                    Console.Write(" [ ] ");
                }
                else
                {
                    Console.Write(" [*] ");
                }

                if (i % 5 == 4)
                    Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
            WindowSize();
            Intro();

            double[] z0 = prepareZ0("normal");
            double[] z0_ = prepareZ0("disturbed");
            double[] z1 = prepareZ1("normal");
            double[] z1_ = prepareZ1("disturbed");

            double[][] W = calculateW(z0, z1);
            double[] y;

            // Z0
            Console.WriteLine("z0\tF(z0)");
            Console.WriteLine("------------------------");
            y = calculateF(W, z0);
            displayResults(y);
            Console.WriteLine();

            // Z0 - disturbed
            Console.WriteLine("z0 - zaburzone");
            Console.WriteLine("------------------------");
            displayResults(z0_);
            Console.WriteLine();

            // Z0 - disturbed result
            Console.WriteLine("z0 - zaburzone (rezultat)\tF(z0')");
            Console.WriteLine("--------------------------------------");
            y = calculateF(W, z0_);
            displayResults(y);
            Console.WriteLine();

            Console.WriteLine();
            Console.WriteLine();

            // Z1
            Console.WriteLine("z1\tF(z1)");
            Console.WriteLine("------------------------");
            y = calculateF(W, z1);
            displayResults(y);
            Console.WriteLine();

            // Z1 - disturbed
            Console.WriteLine("z1 - zaburzone");
            Console.WriteLine("------------------------");
            displayResults(z1_);
            Console.WriteLine();

            // Z1 - disturbed result
            Console.WriteLine("z1 - zaburzone (rezultat)\tF(z1')");
            Console.WriteLine("--------------------------------------");
            y = calculateF(W, z1_);
            displayResults(y);
            Console.WriteLine();

            Console.WriteLine();
            Console.Write("Aby zakończyć, wciśnij dowolny klawisz...");
            Console.ReadKey();
        }
    }
}
