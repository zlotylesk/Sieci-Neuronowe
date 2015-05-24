using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SNE_01
{
    class Program
    {
        static void Intro()
        {
            Console.WriteLine("Wprowadzenie do teorii sieci neuronowych - ćwiczenia.");
            Console.WriteLine("DSNE - Ćwiczenie 1.");
            Console.WriteLine("# Model McCullocha-Pittsa");
            Console.WriteLine("*****************************************************");
            Console.WriteLine();
        }

        static void WindowSize()
        {
            Console.SetWindowSize(Math.Min(110, Console.LargestWindowWidth), Math.Min(35, Console.LargestWindowHeight));
        }

        static void Gate(string logic_gate, List<double> w)
        {
            double y = 0.0;
            if (logic_gate == "NOT")
            {
                double[] u1 = new double[2] { 0, 1 };
                double[] u2 = new double[2] { 1, 1 };

                List<double[]> u = new List<double[]>() { u1, u2 };

                Console.WriteLine("u1\ty\tw[i] * u[i]");
                for (int i = 0; i < u.Count; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        y += w[j] * u[i][j];
                    }
                    if (y >= 0)
                        Console.WriteLine(u[i][0] + "\t" + 1.0 + "\t" + y);
                    else
                        Console.WriteLine(u[i][0] + "\t" + 0.0 + "\t" + y);
                    y = 0.0;
                }
            }

            if (logic_gate == "AND" || logic_gate == "NAND" || logic_gate == "OR")
            {
                double[] u1 = new double[3] { 0, 0, 1 };
                double[] u2 = new double[3] { 0, 1, 1 };
                double[] u3 = new double[3] { 1, 0, 1 };
                double[] u4 = new double[3] { 1, 1, 1 };

                List<double[]> u = new List<double[]>() { u1, u2, u3, u4 };

                Console.WriteLine("u1\tu2\ty\tw[i] * u[i]");
                for (int i = 0; i < u.Count; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {                       
                        y += w[j] * u[i][j];
                    }
                    if (y >= 0)
                        Console.WriteLine(u[i][0] + "\t" + u[i][1] + "\t" + 1.0 + "\t" + y);
                    else
                        Console.WriteLine(u[i][0] + "\t" + u[i][1] + "\t" + 0.0 + "\t" + y);
                    y = 0.0;
                }
            }
        }

        static void Main(string[] args)
        {
            WindowSize();
            Intro();
            
            List<double> weights = new List<double>();

            //NOT
            Console.WriteLine("NOT:");
            Console.WriteLine("*********");
            weights.Add(-0.5);
            weights.Add(0.33);
            Gate("NOT", weights);
            weights.Clear();

            Console.WriteLine();

            //AND
            Console.WriteLine("AND:");
            Console.WriteLine("*****************");
            weights.Add(0.33);
            weights.Add(0.33);
            weights.Add(-0.5);            
            Gate("AND", weights);
            weights.Clear();

            Console.WriteLine();

            //NAND
            Console.WriteLine("NAND:");
            Console.WriteLine("*****************");
            weights.Add(-0.33);
            weights.Add(-0.33);
            weights.Add(0.5);
            Gate("NAND", weights);
            weights.Clear();

            Console.WriteLine();

            //OR
            Console.WriteLine("OR:");
            Console.WriteLine("*****************");
            weights.Add(0.33);
            weights.Add(0.33);
            weights.Add(-0.33);
            Gate("OR", weights);
            weights.Clear();

            Console.WriteLine();
            Console.Write("Aby zakończyć, wciśnij dowolny klawisz...");
            Console.ReadKey();
        }
    }
}
