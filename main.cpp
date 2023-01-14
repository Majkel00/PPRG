/*
	Testowane dla:

	0 6 0 3 0 0 8 0 4 5 3 7 0 9 0 0 0 0 0 4 0 0 0 6 3 0 7 0 9 0 0 5 1 2 3 8 0 0 0 0 0 0 0 0 0 7 1 3 6 2 0 0 4 0 3 0 6 4 0 0 0 1 0 0 0 0 0 6 0 5 2 3 1 0 2 0 0 9 0 8 0


	7 0 0 0 0 0 0 0 6 0 0 5 0 0 0 2 0 0 0 3 0 4 0 7 0 9 0 0 0 2 1 0 8 5 0 0 3 0 0 7 0 9 0 0 1 0 0 9 2 0 4 3 0 0 0 8 0 9 0 1 0 5 0 0 0 3 0 0 0 7 0 0 1 0 0 0 0 0 0 0 8

	8 0 0 0 0 0 0 0 0 0 0 3 6 0 0 0 0 0 0 7 0 0 9 0 2 0 0 0 5 0 0 0 7 0 0 0 0 0 0 0 4 5 7 0 0 0 0 0 1 0 0 0 3 0 0 0 1 0 0 0 0 6 8 0 0 8 5 0 0 0 1 0 0 9 0 0 0 0 4 0 0


*/

#include <iostream>
using namespace std;

const short dim = 9;
short board[dim][dim];

bool check3x3(int starty, int startx, int val)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[y + starty][x + startx] == val)
			{
				return false;
			}
		}
	}

	return true;
}

bool checkColumn(int x, int val)
{
	for (int i = 0; i < dim; i++)
	{
		if (board[i][x] == val)
		{
			return false;
		}
	}

	return true;
}

bool checkRow(int y, int val)
{
	for (int i = 0; i < dim; i++)
	{
		if (board[y][i] == val)
		{
			return false;
		}
	}

	return true;
}

bool solve()
{
	int y;
	int x;
	bool found = false;

	for (y = 0; y < dim; y++)
	{
		for (x = 0; x < dim; x++)
		{
			if (board[y][x] <= 0)
			{
				found = true;
				break;
			}
		}
		if (found) break;
	}
	if (!found) return true;

	for (int i = 1; i < 10; i++)
	{
		if (checkRow(y, i) && checkColumn(x, i) && check3x3((y / 3) * 3, (x / 3) * 3, i))
		{
			board[y][x] = i;
			if (solve())
			{
				return true;
			}
			board[y][x] = 0;
		}
	}

	return false;
}

int main()
{

	for (int i = 0; i < dim; i++)
	{
		for (int z = 0; z < dim; z++)
		{
			cin >> board[i][z];
		}
	}

	cout << endl;



	if (solve())
	{
		for (int y = 0; y < dim; y++)
		{
			for (int x = 0; x < dim; x++)
			{
				cout << board[y][x] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Nieprawidlowe sudoku" << endl;
	}
}
