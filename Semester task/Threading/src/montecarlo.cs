using System;
using System.Diagnostics;

namespace Threading
{
    public class montecarlo
    {
        public struct PiData
        {
            public Thread[] threads;
            public long[] results;
            public int pointsPerThread;
        }

        public static double calcPi(long totalRes, int numPoints)
        {
            double pi = 4.0 * totalRes / numPoints;
            return pi;
        }

        public static void makeThreads(PiData piData, int numThreads)
        {
            Random random = new Random();

            for (int i = 0; i < numThreads; i++)
            {
                int threadIndex = i;
                piData.threads[i] = new Thread(() =>
                {
                    long threadResult = 0;

                    for (int j = 0; j < piData.pointsPerThread; j++)
                    {
                        double x = random.NextDouble();
                        double y = random.NextDouble();

                        if (x * x + y * y <= 1)
                        {
                            threadResult++;
                        }
                    }

                    piData.results[threadIndex] = threadResult;
                });
            }
        }

        public static void generateRand(PiData piData)
        {
            Random random = new Random();
            long threadResult = 0;

            for (int j = 0; j < piData.pointsPerThread; j++)
            {
                double x = random.NextDouble();
                double y = random.NextDouble();

                if (x * x + y * y <= 1)
                {
                    threadResult++;
                }
            }

            piData.results[0] = threadResult;
        }
        public static double[] generatePIParallel(int numThreads, int numPoints, PiData piData)
        {
            Stopwatch time = new Stopwatch();
            double[] output = new double[2];
            piData.results = new long[numThreads];
            piData.threads = new Thread[numThreads];
            piData.pointsPerThread = numPoints / numThreads;

            time.Start();

            makeThreads(piData, numThreads);

            for (int i = 0; i < numThreads; i++)
            {
                piData.threads[i].Start();
            }

            for (int i = 0; i < numThreads; i++)
            {
                piData.threads[i].Join();
            }

            long totalResult = 0;

            for (int i = 0; i < numThreads; i++)
            {
                totalResult += piData.results[i];
            }

            output[0] = calcPi(totalResult, numPoints);

            time.Stop();

            output[1] = (double)time.ElapsedMilliseconds;

            return output;
        }

        public static double[] generatePISeq(int numPoints, PiData piData)
        {
            Stopwatch time = new Stopwatch();
            double[] output = new double[2];
            piData.results = new long[1];
            piData.threads = new Thread[1];
            piData.pointsPerThread = numPoints;

            time.Start();

            generateRand(piData);

            output[0] = calcPi(piData.results[0], numPoints);

            time.Stop();

            output[1] = (double)time.ElapsedMilliseconds;

            return output;
        }
    }
}
