# Sudoku-Puzzle

About the project

Sudoku is a popular number puzzle and this program helps the user to do the same.
It is a simple c++ code and uses backtracking for its purpose. The program is divided
into functions for easy flow.

Technology used

C++ is used for coding and recursion is used a main key to solve the puzzle. Thus
saving ourselves from running into every possible solution. The recursion does that
thing for us.

Apart from this the whole program is coded using simple C++ concepts like 2d array,
pointers, functions etc.

Running the program
First make sure you have the code and an IDE or gcc compiler for running the code.

Compile the code and program will ask to enter the Sudoku puzzle row by row. Here
you need to enter a 9 by 9 Sudoku puzzle. In case any wrong unsolved puzzle will be
entered the program will declare it invalid and will print no solution on the output
screen.

After inputting the puzzle the functions will take the control and the solving process
will start.

Function(s) used
1) Main()

Main function is place from where the execution will start, here the input of
array or Sudoku is taken and is passed to different function for further use.

2) SolveSudoku

This program is the most important function in the program. It takes the
Sudoku, a 2d array and then looks for some empty space in the matrix. After
finding the location it put a number on that location and check if it is valid or
not, by applying the rules of Sudoku.
The whole process goes on and on using recursive functions and at the end
the Sudoku is solved.

3) UnassignedLocation

In order to solve the souk or puzzle, program to need to search for empty
places so
This function looks for empty position in the Sudoku represented by ‘0’, and
returns a bool value accordingly.

4) isSafe

During the hit and trial approach this function will help the program to ensure
the validity of that number at that particular empty location. usedinbox(),
usedinrow() and usedincol() will be used to ensure that the chosen number is
not in the 3 by 3 box, in that particular row and in that particular column
respectively.

5) UsedInBox

This function looks if the number is not occurring in the box i.e. in that 3*
grid where it will be placed as according to rules of Sudoku one can only use a
number out of 1 to 9 only once in this 3*3 grid.

6) UsedInCol

This function will ensure that the number(int num) is unique in the column
where it is supposed to be filled. It will return a bool value according to the
outcome.

7) UsedInRow

Similar to previous one, This function will ensure that the number(int num) is
unique in the column where it is supposed to be filled. It will return a bool
value according to the outcome.

8) print_it

This function will simply print the solved Sudoku puzzle on the output screen.
