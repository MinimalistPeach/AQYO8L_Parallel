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

        public static double calcPI(long totalres, int numPoints)
        {
            double pi = 4.0 * totalres / numPoints;
            return pi;
        }

        public static void makeThreads(PiData pidata, int numThreads)
        {
            Random random = new Random();

            for (int i = 0; i < numThreads; i++)
            {
                int threadIndex = i;
                pidata.threads[i] = new Thread(() =>
                {
                    long threadResult = 0;

                    for (int j = 0; j < pidata.pointsPerThread; j++)
                    {
                        double x = random.NextDouble();
                        double y = random.NextDouble();

                        if (x * x + y * y <= 1)
                        {
                            threadResult++;
                        }
                    }

                    pidata.results[threadIndex] = threadResult;
                });
            }
        }

        public static void generateRand(PiData pidata)
        {
            Random random = new Random();
            long threadResult = 0;

            for (int j = 0; j < pidata.pointsPerThread; j++)
            {
                double x = random.NextDouble();
                double y = random.NextDouble();

                if (x * x + y * y <= 1)
                {
                    threadResult++;
                }
            }

            pidata.results[0] = threadResult;
        }
        public static double[] generatePIParallel(int numThreads, int numPoints, PiData pidata)
        {
            Stopwatch time = new Stopwatch();
            double[] output = new double[2];
            pidata.results = new long[numThreads];
            pidata.threads = new Thread[numThreads];
            pidata.pointsPerThread = numPoints / numThreads;

            time.Start();

            makeThreads(pidata, numThreads);

            for (int i = 0; i < numThreads; i++)
            {
                pidata.threads[i].Start();
            }

            for (int i = 0; i < numThreads; i++)
            {
                pidata.threads[i].Join();
            }

            long totalResult = 0;

            for (int i = 0; i < numThreads; i++)
            {
                totalResult += pidata.results[i];
            }

            output[0] = calcPI(totalResult, numPoints);

            time.Stop();

            output[1] = (double)time.ElapsedMilliseconds;

            return output;
        }

        public static double[] generatePISeq(int numPoints, PiData pidata)
        {
            Stopwatch time = new Stopwatch();
            double[] output = new double[2];
            pidata.results = new long[1];
            pidata.threads = new Thread[1];
            pidata.pointsPerThread = numPoints;

            time.Start();

            generateRand(pidata);

            output[0] = calcPI(pidata.results[0], numPoints);

            time.Stop();

            output[1] = (double)time.ElapsedMilliseconds;

            return output;
        }
    }
}
