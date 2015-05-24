using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace SNE_02
{
    class Program
    {
        static void Intro()
        {
            Console.WriteLine("Wprowadzenie do teorii sieci neuronowych - ćwiczenia.");
            Console.WriteLine("DSNE - Ćwiczenie 2.");
            Console.WriteLine("# Perceptron");
            Console.WriteLine("*****************************************************");
            Console.WriteLine();
        }

        static void WindowSize()
        {
            Console.SetWindowSize(Math.Min(110, Console.LargestWindowWidth), Math.Min(40, Console.LargestWindowHeight));
        }

        static string DisplayDouble(double value)
        {
            CultureInfo USFormat = new CultureInfo("en-US");
            return value.ToString("0.00", USFormat);
        }

        // Set all values to 0.0 for vector "u" OR to 1.0 for vector "w"
        static double[] getClearVector(double value)
        {
            double[] vector = new double[26];
            for (int i = 0; i < 26; i++)
            {
                vector[i] = value;
            }
            return vector;
        }

        // Preparing all vectors
        static List<double[]> prepareU()
        {            
            // Filling up values in "u1" vector
            double[] u1 = new double[26];
            u1 = getClearVector(0.0);
            u1[6] = 1.0; 
            u1[7] = 1.0; 
            u1[12] = 1.0; 
            u1[17] = 1.0; 
            u1[22] = 1.0; 
            u1[25] = 1.0;

            // Filling up values in "u2" vector
            double[] u2 = new double[26];
            u2 = getClearVector(0.0);
            u2[2] = 1.0; 
            u2[3] = 1.0; 
            u2[8] = 1.0; 
            u2[13] = 1.0; 
            u2[25] = 1.0;

            // Filling up values in "u3" vector
            double[] u3 = new double[26];
            u3 = getClearVector(0.0);
            u3[5] = 1.0; 
            u3[6] = 1.0; 
            u3[11] = 1.0; 
            u3[16] = 1.0; 
            u3[21] = 1.0; 
            u3[25] = 1.0;

            // Filling up values in "u4" vector
            double[] u4 = new double[26];
            u4 = getClearVector(0.0);
            u4[6] = 1.0; 
            u4[7] = 1.0; 
            u4[8] = 1.0; 
            u4[11] = 1.0; 
            u4[13] = 1.0; 
            u4[16] = 1.0; 
            u4[17] = 1.0; 
            u4[18] = 1.0; 
            u4[25] = 1.0;
            
            // Filling up values in "u5" vector
            double[] u5 = new double[26];
            u5 = getClearVector(0.0);
            u5[10] = 1.0; 
            u5[11] = 1.0; 
            u5[12] = 1.0; 
            u5[15] = 1.0; 
            u5[17] = 1.0; 
            u5[20] = 1.0; 
            u5[21] = 1.0; 
            u5[22] = 1.0; 
            u5[25] = 1.0;

            List<double[]> u = new List<double[]>() { u1, u2, u3, u4, u5 };
            return u;
        }

        static double setZ(int t)
        {
            if (1 + ((t - 1) % 5) <= 3)
                return 1.0;
            else
                return 0.0;
        }

        static double getY(double[] w, double[] u)
        {
            double y = 0.0;
            for (int i = 0; i < 26; i++)
            {
                y += w[i] * u[i];
            }

            if (y >= 0)
                return 1.0;
            else
                return 0.0;
        }

        static void PerceptronAlgorithm(double c)
        {
            // Algorithm

            int counter = 0;
            int t = 1;
            double y;
            double z;

            // Set all values to 1.0 for vector "w"
            double[] w = new double[26];
            w = getClearVector(1.0);

            // List of "u" vectors
            List<double[]> u = new List<double[]>();
            u = prepareU();

            while (counter != 5)
            {
                z = setZ(t);
                y = getY(w, u[(t - 1) % 5]);

                for (int i = 0; i < 26; i++)
                {
                    w[i] = w[i] + c * (z - y) * u[(t - 1) % 5][i];
                }

                t += 1;
                if (z == y)
                    counter += 1;
                else
                    counter = 0;
            }

            // Display results
            Console.WriteLine("c = " + c + ", " + "t = " + t);
            Console.WriteLine("-------------------");

            int index = 0;
            for (int rows = 1; rows < 6; rows++)
            {
                for (int cols = 1; cols < 6; cols++)
                {
                    Console.Write(DisplayDouble(w[index]) + "\t");
                    index++;
                }
                if (rows == 5)
                    Console.WriteLine(DisplayDouble(w[25]));
                
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
            WindowSize();
            Intro();

            // Running perceptron algorithm with different "c" value
            PerceptronAlgorithm(0.01);
            Console.WriteLine();
            PerceptronAlgorithm(0.1);
            Console.WriteLine();
            PerceptronAlgorithm(1);
         
            Console.WriteLine();
            Console.Write("Aby zakończyć, wciśnij dowolny klawisz...");
            Console.ReadKey();
        }
    }
}
