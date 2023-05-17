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

            double[] LeibnizPIAndTimeSeq = new double[2];
            double[] LeibnizPIAndTimePar = new double[2];
            int numPoints, numThreads, precision;
            numPoints = 0;
            numThreads = 0;
            precision = 0;
            if (args.Length < 3)
            {
                Console.WriteLine("Hasznalat: pi_det.exe <szalak szama> <pontok szama> <iteraciok szama>");
                System.Environment.Exit(0);
            }
            else
            {
                numThreads = int.Parse(args[0]);
                numPoints = int.Parse(args[1]);  
                precision = int.Parse(args[2]);
            }

            PIAndTimePar = montecarlo.generatePIParallel(numThreads, numPoints, piData);

            Console.WriteLine("A Pi kozelitese Monte Carlo modszerrel tobb szalon: {0:F15}", PIAndTimePar[0]);
            Console.WriteLine("Monte Carlo modszerrel {0} szalon, {1} db pontot felhasznalva, parhuzamosan {2} ms-be telt a szamitas.", numThreads, numPoints, PIAndTimePar[1]);

            Console.WriteLine(" ");

            PIAndTimeSeq = montecarlo.generatePISeq(numPoints, piData);

            Console.WriteLine("A Pi kozelitese Monte Carlo modszerrel szekvencialisan: {0:F15}", PIAndTimeSeq[0]);
            Console.WriteLine("Monte Carlo modszerrel {0} db pontot felhasznalva, szekvencialisan {1} ms-be telt a szamitas.", numPoints, PIAndTimeSeq[1]);

            Console.WriteLine("Monte Carlo modszerrel a PI kozelites parhuzamos es szekvencialis ido kulonbsege {0} ms", Math.Abs(PIAndTimePar[1] - PIAndTimeSeq[1]));
           
            Console.WriteLine(" ");
            Console.WriteLine(" ");

            LeibnizPIAndTimeSeq = Leibniz.calculatePiSeq(precision);
            Console.WriteLine("Leibniz modszerrel a PI kozelitese szekvencialisan: {0}", LeibnizPIAndTimeSeq[0]);
            Console.WriteLine("Leibniz modszerrel a PI kozelitese szekvencialisan {0} iteracioval {1} ms-t vett igenybe.", precision, LeibnizPIAndTimeSeq[1]);

            LeibnizPIAndTimePar = Leibniz.calculatePiPar(numThreads, precision);
            Console.WriteLine("Leibniz modszerrel a PI kozelitese parhuzamosan: {0}", LeibnizPIAndTimePar[0]);
            Console.WriteLine("Leibniz modszerrel a PI kozelitese parhuzamosan {0} iteracioval {1} szalon {2} ms-t vett igenybe.", precision, numThreads, LeibnizPIAndTimePar[1]);
            Console.WriteLine("Leibniz modszerrel a PI kozelites parhuzamos es szekvencialis ido kulonbsege {0} ms", Math.Abs(LeibnizPIAndTimePar[1] - LeibnizPIAndTimeSeq[1]));
        }
    }

}