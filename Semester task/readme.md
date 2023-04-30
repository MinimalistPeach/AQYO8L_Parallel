
# (C) Matrix multiplication using OpenMP parallel threads

My first semester task is about matrix multiplication with the use of OpenMP library. 


## Features

- The program multiplies two matrices with the size given by the user.
- The user can determine the number of threads in the form of a command line argument
- The program uses the row-column method, which multiplies the first matrix's rows and columns with the second matrix's rows and columns, then puts it in the output matrix's rows and columns

## Usage

After compiling the program, the user can run the matrix_mult.exe file from the commandline.
The arguments are the following:
<br />
```CLI
  .\matrix_mult.exe <1. array size (n x n)> .... <n. array size (n x n)> <number of threads>
```
The program will output the running time of the matrix multiplication with and without parallelization.
<br />

# (C) BFS graph algorithm using pthread parallel threads

My second semester task is about the usage of BFS Graph algorithm to go through a graph. It uses the pthread library for parallelization.

## Features

- The user can determine the number of nodes and threads used in the program
- The program calculates the time that takes to go from the top of the graph to the bottom, then displays both sequential and parallel time
- The program goes through all the nodes with a recursive method, meanwhile it saves the already read nodes


## Usage

After compiling the program, the user can run the bfs_alg.exe file from the commandline.
The arguments are the following:
<br />
```CLI
  .\bfs_alg.exe <number of nodes> <number of threads>
```
The program will output the running time of the matrix multiplication with and without parallelization.
<br />

# (C#) PI value determination using the Monte Carlo algorithm and Leibniz method

## Features
- The program gets the number of threads and number of points as a command line argument, then determines how many random points are in the circle's radius, then it calculates the PI value (Monte Carlo)
- The program gets the polygon's number of sides, the samplenumber, the circle's radius, the inner and outer circles radius from the command line, then the algorithm calculates the polygon's sides length and it's origin then it writes circles inside and outside of the polygon and the area's rate between the two gives the approximation of the PI. (Archimedes)


## Usage

After compiling the program, the user can run the pi_det.exe file from the commandline.
The arguments are the following:
<br />
```CLI
  .\pi_det.exe <number of threads> <number of points> <iterations>
```
The program will output the running time of the algorithms with and without parallelization.

# Installation

To make the C files you will need a C compiler and Make.
For the C# program you will need DotNET SDK 4.8.0 and .NET Framework 6.0 installed.
You can compile all of the programs at once with the Makefile in the Semester task directory.
Alternatively, you can compile the programs one by one in their own directory. The C# program will build in the output directory.

You can compile the programs one by one using the following commands:
```Make
  make win
 ```
  or
  ```Make
  make linux
```
<br />
To compile all the program at once run the following command:
```Make
  make all
```
<br />
You can only run the programs from the terminal with the following command:
```CLI
  .\{program_name.exe} <arguments..>
```