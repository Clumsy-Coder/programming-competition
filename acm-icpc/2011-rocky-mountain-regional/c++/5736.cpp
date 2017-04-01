#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int row, col;
};

bool threshold(const int &i)
{
	return i < 5;
}

void readInput();
void solve();
void move();
void print();
void printAns(vector<int> &contours);

int numRow, numCol, cases = 1;
char grid [202][202];

int dirX [8] = { 0 , -1 , -1 , -1 , 0 , 1 , 1 ,  1 };
int dirY [8] = {-1 , -1 ,  0 ,  1 , 1 , 1 , 0 , -1 };
node start, curNode;

int main()
{
	while(cin >> numRow >> numCol && (numRow && numCol))
	{
		readInput();
		print();
		cout << "Case " << cases++ << endl;
		solve();
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
}

void print()
{
	for(int i = 1; i <= numRow; i++)
	{
		for(int k = 1; k <= numCol; k++)
		{
			if(i == curNode.row && k == curNode.col)
			{
				cout << 'c';
			}
			else if(i == start.row && k == start.col)
			{
				cout << "s";
			}
			else if(grid[i][k] != '0')
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

void solve()
{
	int numPixels = 0;
	int rowMax = 1;
	vector<int> contours;
	pair<int, int> b0, c0;
	pair<int, int> b1, c1;
	pair<int, int> b, c;
	bool done = false;

	//step 1
	for(int curRow = 1; curRow <= numRow && !done; curRow++)
	{
		for(int curCol = 1; curCol <= numCol && !done; curCol++)
		{
			//searching for the start
			if(grid[curRow][curCol] == '1')
			{
				b0.first = curRow;
				b0.second = curCol;
				c0.first = b0.first;
				c0.second = b0.second + dirY[0];

				// rowMax = curRow;
				curRow = curCol = 250;	//get out of the loop
			}
		}
	}

	//step 2
	while(!done)
	{
		for(int i = 0; i < 8 && !done; i++)
		{
			for(int k = 0; k < 8 && !done; k++)
			{
				rowMax = max(rowMax, rowMax + dirX[i]);

				// if( grid[curNode.row + dirX[i]][curNode.col + dirY[k]] == '1' )
				// {
				// 	curNode.row = curNode.row + dirX[i];
				// 	curNode.col = curNode.col + dirY[k];
				// 	numPixels;
				// }

				if( grid[b0.first + dirX[i]][b0.second + dirY[k]] == '1' )
				{
					b1.first = b0.first + dirX[i];
					b1.second = b0.second + dirY[k];

				}

				print();
			}
		}
	}

	printAns(contours);
}

void printAns(vector<int> &contours)
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