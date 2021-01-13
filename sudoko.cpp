#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0

#define N 9

// This function finds an entry in grid
// that is still unassigned
bool UnassignedLocation(int grid[N][N],int& row, int& col);

// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(int grid[N][N], int row,int col, int num);

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool SolveSudoku(int grid[N][N])
{
	int row, col;

	// If there is no unassigned location,
	// we are done
	if (!UnassignedLocation(grid, row, col))
		// success!
		return true;

	// Consider digits 1 to 9
	for (int num = 1; num <= 9; num++)
	{

		// Check if looks promising
		if (isSafe(grid, row, col, num))
		{

			// Make tentative assignment
			grid[row][col] = num;

			// Return, if success
			if (SolveSudoku(grid))
				return true;

			// Failure, unmake & try again
			grid[row][col] = UNASSIGNED;
		}
	}

	// This triggers backtracking
	return false;
}

bool UnassignedLocation(int grid[N][N],int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

bool UsedInRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow,
			int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow][col + boxStartCol] ==num)
				return true;
	return false;
}

bool isSafe(int grid[N][N], int row,int col, int num)
{
	return !UsedInRow(grid, row, num)&& !UsedInCol(grid, col, num)&& !UsedInBox(grid, row - row % 3,col - col % 3, num)
		&& grid[row][col] == UNASSIGNED;
}


void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
}


int main()
{
        int grid[N][N];
        cout<<"Enter the sudoku puzzle row by row \n\n";

            for(int i=0;i<N;i++)
            {
               for(int j=0;j<N;j++)
                    cin>>grid[i][j];
            }



        if (SolveSudoku(grid) == true)
            printGrid(grid);
        else
            cout << "No solution exists\n\n";


        return 0;
}


