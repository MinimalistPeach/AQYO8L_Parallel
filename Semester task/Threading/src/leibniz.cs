using System;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;
using System.Diagnostics;


namespace Threading
{
    public class Leibniz
    {

        public static double[] calculatePiPar(int numThreads, int iterations)
        {
            double[] partialResults = new double[numThreads];
            Thread[] threads = new Thread[numThreads];
            double[] result = new double[2];
            Stopwatch time = new Stopwatch();

            time.Start();
            for (int i = 0; i < numThreads; i++)
            {
                int threadIndex = i;
                threads[i] = new Thread(() =>
                {
                    double partialSum = 0.0;
                    for (int j = threadIndex; j < iterations; j += numThreads)
                    {
                        partialSum += Math.Pow(-1, j) / (2 * j + 1);
                    }
                    partialResults[threadIndex] = partialSum;
                });
                threads[i].Start();
            }

            for (int i = 0; i < numThreads; i++)
            {
                threads[i].Join();
            }

            for (int i = 0; i < numThreads; i++)
            {
                result[0] += partialResults[i];
            }
            result[0] *= 4;

            time.Stop();

            result[1] = time.ElapsedMilliseconds;

            return result;
        }

        public static double[] calculatePiSeq(int iterations)
        {
            Stopwatch time = new Stopwatch();
            double[] result = new double[2];
            result[0] = 0.0;
            double tempRes = 0.0;

            time.Start();

            for (int i = 0; i < iterations; i++)
            {
                tempRes += Math.Pow(-1, i) / (2 * i + 1);
            }

            result[0] = tempRes;
            result[0] = 4 * result[0];

            time.Stop();
            result[1] = time.ElapsedMilliseconds;
            return result;
        }
    }
}