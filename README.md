# Problema-da-Mochila
Solution for a problem in a former online judge (Run Codes) about the "Knapsack problem"


>Status: Complete!

## Technologies used: 
  * C

## Task:

Imagine that you have just won a contest where the prize is to choose any n items from a store. The i-th item has a value of vi dollars and weighs wi kilograms (vi, wi ∈ ℝ). You can take as many items as you want, as long as the chosen items fit in a backpack that can carry up to W kilograms.

The objective is to determine the set of items that you should take so that you can carry them all within the backpack and maximize the total value of the items.

This problem is known as the knapsack problem and has numerous practical applications.

The exercise consists of implementing an algorithm to verify whether a given solution provided as input is an optimal, feasible, or infeasible solution for the knapsack problem with the provided parameters (backpack capacity, item weights, and values).

For example, suppose a backpack with a capacity of 10 kg and the following objects:
.
.
.

Data Input Format:
The program input is a text file whose name will be requested as follows:
printf("Enter the filename: ");

The text file should contain information about the n items in the store in the following order:

On the first line: W (backpack capacity)
On the second line: n (number of items)
On the next n lines: item weights and values, separated by a space, each on a separate line
On the next n lines: the solution to be verified (1 for chosen item, 0 for item not present in the backpack)
Translation:

Imagine you have just won a contest whose prize is to choose any n items from a store. The i-th item has a value of vi dollars and weighs wi kilograms (vi, wi ∈ ℝ). You can take whatever you want, as long as the chosen items fit in a backpack that can carry up to W kilograms.

The goal is to determine the set of items you should take so that you can carry them all inside the backpack and maximize the total value of the items.

This problem is known as the knapsack problem and has numerous practical applications.

The exercise consists of implementing an algorithm to check if a given solution provided as input is an optimal, feasible, or infeasible solution for the knapsack problem with the provided parameters (backpack capacity, item weights, and values).

For example, suppose a backpack with a capacity of 10 kg and the following objects:
.
.
.

Data Input Format:
The program input is a text file whose name will be requested as follows:
printf("Enter the filename: ");

The text file should contain information about the n items in the store in the following order:

On the first line: W (backpack capacity)
On the second line: n (number of items)
On the next n lines: item weights and values, separated by a space, each on a separate line
On the next n lines: the solution to be verified (1 for chosen item, 0 for item absent in the backpack)


<img src="https://github.com/MullerPenaforte/Problema-da-Mochila/assets/129807601/09a25374-76aa-4682-a402-6031653ad01c" width="400">

## How to run the application:
  * First, [download](https://sourceforge.net/projects/mingw/files/OldFiles/) and install the compiler.

  * Then, type the C/C++ program and save it.

  * Then, open the command line and change directory to the particular one where the source file is stored, using cd like so:
  cd C:\Documents and Settings\...
  
  * Then, to compile, type in the command prompt:
  gcc sourcefile_name.c -o outputfile.exe
  
  * Finally, to run the code, type:
  outputfile.exe
