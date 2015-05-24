using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SNE_06
{
    class Program
    {
        static void Intro()
        {
            Console.WriteLine("Wprowadzenie do teorii sieci neuronowych - ćwiczenia.");
            Console.WriteLine("DSNE - Ćwiczenie 6.");
            Console.WriteLine("# Sieci Hopfielda");
            Console.WriteLine("*****************************************************");
            Console.WriteLine();
        }
        static void WindowSize()
        {
            Console.SetWindowSize(Math.Min(110, Console.LargestWindowWidth), Math.Min(40, Console.LargestWindowHeight));
        }

        // Set all values to "value" for vector
        static double[] getClearVector(double value)
        {
            double[] vector = new double[25];
            for (int i = 0; i < 25; i++)
            {
                vector[i] = value;
            }
            return vector;
        }

        static double[][] calculateCij(double[] xs)
        {
            double[][] cij = new double[25][];
            for (int i = 0; i < 25; i++)
            {
                cij[i] = new double[25];
                cij[i] = getClearVector(0.0);
            }

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    if (i == j)
                        cij[i][j] = 0.0;
                    else
                    {
                        cij[i][j] = (xs[i] - 0.5) * (xs[j] - 0.5);
                    }
                }
            }

            return cij;
        }

        static double[][] calculateDij(double[] xr)
        {
            double[][] dij = new double[25][];
            for (int i = 0; i < 25; i++)
            {
                dij[i] = new double[25];
                dij[i] = getClearVector(0.0);
            }

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    if (i == j)
                        dij[i][j] = 0.0;
                    else
                    {
                        dij[i][j] = (xr[i] - 0.5) * (xr[j] - 0.5);
                    }
                }
            }

            return dij;
        }

        static double[][] calculateWij(double[][] cij)
        {
            double[][] wij = new double[25][];
            for (int i = 0; i < 25; i++)
            {
                wij[i] = new double[25];
                wij[i] = getClearVector(0.0);
            }

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    wij[i][j] = 2 * cij[i][j];
                }
            }

            return wij;
        }

        static double[][] calculateWij(double[][] cij, double[][] dij)
        {
            double[][] wij = new double[25][];
            for (int i = 0; i < 25; i++)
            {
                wij[i] = new double[25];
                wij[i] = getClearVector(0.0);
            }

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    wij[i][j] = 2 * (cij[i][j] + dij[i][j]);
                }
            }

            return wij;
        }

        static double[] calculateTheta(double[][] cij)
        {
            double[] theta = new double[25];
            theta = getClearVector(0.0);

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    theta[i] += cij[i][j];
                }
            }

            return theta;
        }

        static double[] calculateTheta(double[][] cij, double[][] dij)
        {
            double[] theta = new double[25];
            theta = getClearVector(0.0);

            for (int i = 0; i < 25; i++)
            {
                for (int j = 0; j < 25; j++)
                {
                    theta[i] += cij[i][j] + dij[i][j];
                }
            }

            return theta;
        }

        static void displayResults(double[] vector)
        {
            for (int i = 0; i < 25; i++)
            {
                if (vector[i] == 0.0)
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

        static void hopfieldAlgorithm(double[] x, string type)
        {
            double[][] cij;
            double[][] dij;
            double[][] wij;
            double[] theta;

            // Prepare ui vector
            double[] ui = new double[25];
            ui = getClearVector(0.0);

            // Random
            double[] random = new double[25];
            Random rnd = new Random();
            for (int i = 0; i < 25; i++)
            {
                random[i] = rnd.NextDouble();
            }

            // x(t) and x(t+1)
            double[] x_prev = new double[25];
            x_prev = getClearVector(0.0);
            double[] x_next= new double[25];
            x_next = getClearVector(0.0);

            if (type == "first")
            {
                Console.WriteLine("(1)");
                Console.WriteLine();
                for (int i = 0; i < 25; i++)
                {
                    if (random[i] <= 0.5)
                        x_prev[i] = 0.0;
                    else
                        x_prev[i] = 1.0;
                }
                Console.WriteLine("x(0)");
                displayResults(x_prev);

                cij = calculateCij(x);
                wij = calculateWij(cij);
                theta = calculateTheta(cij);

                // Calculate first ui
                for (int i = 0; i < 25; i++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        ui[i] += (wij[i][j] * x_prev[j]) - theta[i];
                    }
                }

                // Calculate ui for t
                for (int t = 1; t < 6; t++)
                {
                    for (int i = 0; i < 25; i++)
                    {
                        if (ui[i] > 0)
                            x_next[i] = 1;

                        else if (ui[i] == 0)
                            x_next[i] = x_prev[i];

                        else
                            x_next[i] = 0;
                    }

                    Console.WriteLine("x(" + t + ")");
                    displayResults(x_next);

                    Array.Copy(x_next, x_prev, x_next.Count());
                    ui = getClearVector(0.0);

                    for (int i = 0; i < 25; i++)
                    {
                        for (int j = 0; j < 25; j++)
                        {
                            ui[i] += (wij[i][j] * x_prev[j]) - theta[i];
                        }
                    }
                }
                Console.WriteLine("...");
            }

            if (type == "second")
            {
                Console.WriteLine("(2)");
                Console.WriteLine();
                for (int i = 0; i < 25; i++)
                {
                    if (random[i] <= 0.5)
                        x_prev[i] = 0.0;
                    else
                        x_prev[i] = 1.0;
                }
                Console.WriteLine("x(0)");
                displayResults(x_prev);

                cij = calculateCij(x);
                dij = calculateDij(x);
                wij = calculateWij(cij, dij);
                theta = calculateTheta(cij, dij);

                // Calculate first ui
                for (int i = 0; i < 25; i++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        ui[i] += (wij[i][j] * x_prev[j]) - theta[i];
                    }
                }

                // Calculate ui for t
                for (int t = 1; t < 6; t++)
                {
                    for (int i = 0; i < 25; i++)
                    {
                        if (ui[i] > 0)
                            x_next[i] = 1;

                        else if (ui[i] == 0)
                            x_next[i] = x_prev[i];

                        else
                            x_next[i] = 0;
                    }

                    Console.WriteLine("x(" + t + ")");
                    displayResults(x_next);

                    Array.Copy(x_next, x_prev, x_next.Count());
                    ui = getClearVector(0.0);

                    for (int i = 0; i < 25; i++)
                    {
                        for (int j = 0; j < 25; j++)
                        {
                            ui[i] += (wij[i][j] * x_prev[j]) - theta[i];
                        }
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            Intro();
            WindowSize();

            // "s" constant vector
            double[] xs = new double[25];
            xs = getClearVector(0.0);
            xs[6] = 1.0;
            xs[7] = 1.0;
            xs[12] = 1.0;
            xs[17] = 1.0;
            xs[22] = 1.0;

            // "r" constant vector
            double[] xr = new double[25];
            xr = getClearVector(0.0);
            xr[1] = 1.0;
            xr[2] = 1.0;
            xr[3] = 1.0;
            xr[6] = 1.0;
            xr[8] = 1.0;
            xr[11] = 1.0;
            xr[13] = 1.0;
            xr[16] = 1.0;
            xr[18] = 1.0;
            xr[21] = 1.0;
            xr[22] = 1.0;
            xr[23] = 1.0;

            // First solution
            hopfieldAlgorithm(xs, "first");

            Console.WriteLine();
            Console.Write("Wciśnij dowolny klawisz...");
            Console.ReadKey();
            Console.WriteLine();
            Console.WriteLine();

            // Second solution
            hopfieldAlgorithm(xr, "second");

            Console.WriteLine();
            Console.Write("Aby zakończyć, wciśnij dowolny klawisz...");
            Console.ReadKey();
        }
    }
}
