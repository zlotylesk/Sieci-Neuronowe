using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace SNE_04
{
    class Program
    {
        // Global constant values (c and epsilon)
        static double c = 0.01;
        static double epsilon = 0.00000001;

        static void Intro()
        {
            Console.WriteLine("Wprowadzenie do teorii sieci neuronowych - ćwiczenia.");
            Console.WriteLine("DSNE - Ćwiczenie 4.");
            Console.WriteLine("# Metoda gradientu");
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
            return value.ToString("0.000000", USFormat);
        }

        static double calculateF(double[] xt)
        {
            return 2 * Math.Pow(xt[0], 2) + 2 * Math.Pow(xt[1], 2) + Math.Pow(xt[2], 2) - 2 * xt[0] * xt[1] - 2 * xt[1] * xt[2] - 2 * xt[1] + 3;
        }

        static double calculateG(double[] xt)
        {
            return 3 * Math.Pow(xt[0], 4) + 4 * Math.Pow(xt[0], 3) - 12 * Math.Pow(xt[0], 2) + 12 * Math.Pow(xt[1], 2) - 24 * xt[1];
        }

        static bool max(double[] xt_new, double[] xt_old, char functionName)
        {
            double max = 0.0;

            if (functionName == 'f')
            {
                for (int i = 0; i < 3; i++)
                {
                    if (Math.Abs(xt_new[i] - xt_old[i]) > max)
                    {
                        max = Math.Abs(xt_new[i] - xt_old[i]);
                    }
                }
            }

            if (functionName == 'g')
            {
                for (int i = 0; i < 2; i++)
                {
                    if (Math.Abs(xt_new[i] - xt_old[i]) > max)
                    {
                        max = Math.Abs(xt_new[i] - xt_old[i]);
                    }
                }
            }

            if (max < epsilon)
                return true;
            else
                return false;
        }

        static void gradientAlgorithm(double[] xt_old, char functionName)
        {
            bool flag = false;
            double result;

            if (functionName == 'f')
            {
                double[] xt_new = new double[3];
                while (flag != true)
                {
                    xt_new[0] = xt_old[0] - c * (4.0 * xt_old[0] - 2.0 * xt_old[1] - 2.0);
                    xt_new[1] = xt_old[1] - c * (-2.0 * xt_old[0] + 4.0 * xt_old[1] - 2.0 * xt_old[2]);
                    xt_new[2] = xt_old[2] - c * (-2.0 * xt_old[1] + 2.0 * xt_old[2]);
                    flag = max(xt_new, xt_old, 'f');
                    Array.Copy(xt_new, xt_old, xt_new.Count());
                }
                Console.WriteLine("(1)");
                Console.WriteLine("x = " + DisplayDouble(xt_new[0]));
                Console.WriteLine("y = " + DisplayDouble(xt_new[1]));
                Console.WriteLine("z = " + DisplayDouble(xt_new[2]));
                result = calculateF(xt_new);
                Console.WriteLine("f(x, y, z) = " + DisplayDouble(result));
            }

            if (functionName == 'g')
            {
                double[] xt_new = new double[2];
                while (flag != true)
                {
                    xt_new[0] = xt_old[0] - c * (12 * Math.Pow(xt_old[0], 3) + 12 * Math.Pow(xt_old[0], 2) - 24 * xt_old[0]);
                    xt_new[1] = xt_old[1] - c * ((24 * xt_old[1]) - 24);
                    flag = max(xt_new, xt_old, 'g');
                    Array.Copy(xt_new, xt_old, xt_new.Count());
                }
                Console.WriteLine("(2)");
                Console.WriteLine("x = " + DisplayDouble(xt_new[0]));
                Console.WriteLine("y = " + DisplayDouble(xt_new[1]));
                result = calculateG(xt_new);
                Console.WriteLine("g(x, y) = " + DisplayDouble(result));
            }
        }

        static void Main(string[] args)
        {
            WindowSize();
            Intro();

            double[] xt;
            
            // Calculate f function - f(x, y, z)
            xt = new double[]
            {
                1, 0, 1
            };
            // Run algorithm
            gradientAlgorithm(xt, 'f');

            Array.Clear(xt, 0, xt.Length);

            Console.WriteLine();
            Console.WriteLine();

            // Calculate g function - g(x, y)            
            xt = new double[]
            {
                4, 4
            };
            // Run algorithm
            gradientAlgorithm(xt, 'g');

            Array.Clear(xt, 0, xt.Length);

            Console.WriteLine();
            Console.Write("Aby zakończyć, wciśnij dowolny klawisz...");
            Console.ReadKey();
        }
    }
}
