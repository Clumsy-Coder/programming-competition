#include <iostream>
#include <algorithm>
#include <unistd.h>

using namespace std;

// struct node
// {
// 	int row, col;
// };

bool threshold(const int &i)
{
	return i < 5;
}

void readInput();
void solve();
void move();
void print(int x, int y);
void printAns();
int scanContour(int x, int y);
void destroy(int x, int y);

int numRow, numCol, cases = 1;
char grid [202][202];

// 				 
// int dirX [8] = { 0 , -1 , -1 , -1 , 0 , 1 , 1 ,  1 };
// int dirY [8] = {-1 , -1 ,  0 ,  1 , 1 , 1 , 0 , -1 };
// 					  N   NE  E   SE  S   SW  W   NW
const int dirX[8] = {-1, -1 , 0 , 1 , 1,  1 , 0, -1 };
const int dirY[8] = { 0,  1 , 1 , 1 , 0, -1, -1, -1 };
// node start, curNode;
int dir = 0;
int numPixels = 0;

vector<int> contours;

void disp(int x, int y)
{
	sleep(1);
	system("clear");
	print(x, y);

}

int main()
{
	while(cin >> numRow >> numCol && (numRow && numCol))
	{
		readInput();
		
		// print();
		cout << "Case " << cases++ << endl;
		solve();


		// printAns();
	}
}

void readInput()
{
	fill(grid[0], grid[201] + 202, '0');
	// cout << count(grid[0], grid[201] + 202, 0) << endl;
	contours.clear();

	for(int i = 1; i <= numRow; i++)
	{
		for(int k = 1; k <= numCol; k++)
		{
			cin >> grid[i][k];
		}
	}
}

void solve()
{
	//step 1
	for(int curRow = 1; curRow <= numRow; curRow++)
	{
		for(int curCol = 1; curCol <= numCol; curCol++)
		{
			//searching for the start
			if(grid[curRow][curCol] == '1')
			{
				
				grid[curRow][curCol - 1] = 'S';				// mark the start of the contour
				disp(curRow, curCol);
				int numPixel = scanContour(curRow, curCol);	// scan the contour
				contours.push_back(numPixel);
				numPixels = 0;
				// grid[curRow][curCol - 1] = '0';				// mark the start to 0
				destroy(curRow, curCol);					// destroy the visited contour
			}
		}
	}
}

int scanContour(int x, int y)
{
	// step 2
	if(grid[x][y] == 'S')
	{
		return 0;
	}

	if(grid[x][y] == '1')
	{
		numPixels++;
	}

	if(grid[x + dirX[4]][y + dirY[4]] == '1' && numPixels < 5)
	{
		// grid[x + dirX[4]][y + dirY[4]] = '2';
		numPixels++;
	}

	// grid[x][y] = '2';
	// dir = (dir + 5) % 8;

	while(grid[x + dirX[dir]][y + dirY[dir]] == '0')
	{
		dir = (dir + 1) % 8;
	}

	return scanContour(x + dirX[dir], y + dirY[dir]) + 1;
	
}

// remove the ones you looked at
void destroy(int x, int y)
{

	if(grid[x][y] == '1')
	{
		for(int i = 0; i < 8; i++)
		{
			destroy(x + dirX[x], y + dirY[y]);
			grid[x][y] = '0';	
		}
	}
}

void printAns()
{
	sort(contours.begin(), contours.end());
	if(count_if(contours.begin(), contours.end(), threshold) == contours.size())
	{
		cout << "no objects found" << endl;
	}
	else
	{
		remove_if(contours.begin(), contours.end(), threshold);
		for(int i = 0; i < contours.size(); i++)
		{
			cout << contours[i] << (i != contours.size() - 1 ? " " : "");
		}

		cout << endl;
	}
}

void print(int x, int y)
{

	for(int i = 1; i <= numRow; i++)
	{
		for(int k = 1; k <= numCol; k++)
		{
			// if(i == curNode.row && k == curNode.col)
			// {
			// 	cout << 'c';
			// }
			// else if(i == start.row && k == start.col)
			// {
			// 	cout << "s";
			// }
			// else if(grid[i][k] != '0')
			// {
				// cout << grid[i][k];
			// }

			// else
			// {
			// 	cout << " ";
			// }
			if(i == x && k == y)
			{
				cout << 'X';
			}
			else
			{
				cout << grid[i][k];
			}
		}

		cout << endl;
	}
}