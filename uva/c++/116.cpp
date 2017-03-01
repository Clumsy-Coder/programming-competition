#include <iostream>

using namespace std;

int main()
{
	int row, col;
	while(cin >> row >> col)
	{
		int matrix [row][col];
		for(int curR = 0; curR < row; curR++)
		{
			for(int curC = 0; curC < col; curC++)
			{
				cin >> matrix[curR][curC];
			}
		}
		
	}
}