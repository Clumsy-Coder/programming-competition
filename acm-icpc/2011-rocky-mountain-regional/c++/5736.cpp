#include <iostream>
#include <algorithm>

using namespace std;

void readInput();
void solve();
void print();

int numRow, numCol;
char grid [202][202];

int main()
{
	while(cin >> numRow >> numCol && (numRow && numCol))
	{
		readInput();
		cout << endl;
	}
}

void readInput()
{
	fill(grid[0], grid[201] + 202, '*');
	// cout << count(grid[0], grid[201] + 202, 0) << endl;

	for(int i = 1; i <= numRow; i++)
	{
		for(int k = 1; k <= numCol; k++)
		{
			cin >> grid[i][k];
		}
	}

	print();


}

void print()
{
	for(int i = 0; i <= numRow + 1; i++)
	{
		for(int k = 0; k <= numCol + 1; k++)
		{
			if(grid[i][k] != '0')
			{
				cout << grid[i][k];
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}
}