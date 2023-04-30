all:
	gcc -fopenmp OpenMP/src/main.c OpenMP/src/parallelgeneration.c OpenMP/src/sequentialgeneration.c OpenMP/src/rng.c OpenMP/src/matrix.c -lmingw32 -IOpenMP/include/ -o matrix_mult.exe
	gcc -pthread pthread/src/main.c pthread/src/node.c pthread/src/bfs.c -lmingw32 -Ipthread/include/ -o bfs_alg.exe
	cd Threading && dotnet build -o ../c#_out/