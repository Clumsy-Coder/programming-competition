//DONE
/*
	Generate the distance from right to left for all elements in the matrix
		distance at col - 1 += min (right, up down)
			right: same row, one column to the right
			up: one row up and column to the right
			down: one row down and one column to the right
	Find the best path (with minimum distance)
	Print the answer
*/

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int row, col;
const int MAX_ROW = 11;
const int MAX_COL = 101;
int matrix [MAX_ROW][MAX_COL];
void generateDist();
void backtrack();

int main()
{
    while(cin >> row >> col)
    {
    	fill(&matrix[0][0], &matrix[row][0], 0);
        for(int curR = 0; curR < row; curR++)
        {
            for(int curC = 0; curC < col; curC++)
            {
                cin >> matrix[curR][curC];
            }
        }

        generateDist();
        backtrack();
    }
}

void generateDist()
{
    for(int curC = col - 1; curC >= 0; curC--)
    {
        for(int curR = 0; curR < row; curR++)
        {
            //left
            int left = matrix[curR][curC + 1];
            //up. if curR = 0, then wrap around to the bottom. curR = row - 1
            int up = matrix[(curR + row - 1) % row][curC + 1];
            //down. if curR = row - 1, then wrap around to the top, curR = 0
            int down = matrix[(curR + 1) % row][curC + 1];

            matrix[curR][curC] += min({left, up, down});
        }
    }
}

void backtrack()
{
    int best = matrix[0][0], index = 0, distance;
    for(int i = 0; i < row; i++)
    {
    	if(matrix[i][0] < best)
		{
			index = i;
			best = matrix[i][0];
		}
    }

    distance = matrix[index][0];

    for(int i = 0; i < col; i++)
    {
    	cout << index + 1;
    	if(i < col - 1)
    	{
    		cout << " ";
    	}
    	int right = matrix[index] [i + 1];
		int up = matrix[(index + row - 1) % row][i + 1];
		int down = matrix[(index + 1) % row][i + 1];

		auto temp = min({pair<int, int>(right, index), 
						 pair<int, int>(up, (index + row - 1) % row), 
						 pair<int, int>(down, (index + 1) % row)});
		index = temp.second;

    }

    cout << endl;
    cout << distance << endl;
}
