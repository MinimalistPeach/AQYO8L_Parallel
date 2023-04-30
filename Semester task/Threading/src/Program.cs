using System;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;


namespace Threading
{
    class main
    {
        static void Main(string[] args)
        {
            montecarlo.PiData piData = new montecarlo.PiData();
            double[] PIAndTimePar = new double[2];
            double[] PIAndTimeSeq = new double[2];
            int numPoints, numThreads;
            numPoints = 0;
            numThreads = 0;
            if(args.Length < 2)
            {
                Console.WriteLine("Hasznalat: pi_det.exe <szalak szama> <pontok szama>");
                System.Environment.Exit(0);
            }
            else
            {
                numPoints = int.Parse(args[1]);
                numThreads = int.Parse(args[0]);
            }
     
            PIAndTimePar = montecarlo.generatePIParallel(numThreads, numPoints, piData);

            Console.WriteLine("A Pi kozelitese: {0:F15}", PIAndTimePar[0]);
            Console.WriteLine("Monte Carlo modszerrel {0} szalon, {1} db pontot felhasznalva, parhuzamosan {2} ms-be telt a szamitas.", numThreads, numPoints, PIAndTimePar[1]);

            PIAndTimeSeq = montecarlo.generatePISeq(numPoints, piData);

            Console.WriteLine("A Pi kozelitese: {0:F15}", PIAndTimeSeq[0]);
            Console.WriteLine("Monte Carlo modszerrel {0} szalon, {1} db pontot felhasznalva, szekvencialisan {2} ms-be telt a szamitas.", numThreads, numPoints, PIAndTimeSeq[1]);

            Console.WriteLine("Monte Carlo modszerrel a PI kozelites parhuzamos es szekvencialis ido kulonbsege {0} ms", Math.Abs(PIAndTimePar[1] - PIAndTimeSeq[1]));
        }
    }

}