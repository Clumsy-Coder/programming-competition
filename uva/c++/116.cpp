#include <iostream>
#include <algorithm>

using namespace std;

int row, col;
const int MAX_ROW = 10;
const int MAX_COL = 100;
int matrix [MAX_ROW][MAX_COL];
int dist [MAX_ROW][MAX_COL];
void generateDist();
void backtrack();

void print()
{
    for(int curR = 0; curR < row; curR++)
    {
        for(int curC = 0; curC < col; curC++)
        {
            cout << matrix[curR][curC] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    while(cin >> row >> col)
    {
        for(int curR = 0; curR < row; curR++)
        {
            for(int curC = 0; curC < col; curC++)
            {
                cin >> matrix[curR][curC];
                if(curC == col - 1)
                {
                    dist[curR][curC] = matrix[curR][curC];
                }
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
            int up = (curR == 0) ? matrix[row - 1][curC + 1] : matrix[(curR - 1) % row][curC + 1];
            //down. if curR = row - 1, then wrap around to the top, curR = 0
            int down = (curR == row - 1) ? matrix[0][curC + 1] : matrix[(curR + 1) % row][curC + 1];

            matrix[curR][curC] = matrix[curR][curC] + min({left, up, down});
        }
    }

    print();
}

void backtrack()
{
    vector<int> path;
    int curLoc [] = {0, 0};
    for(int curC = 0; curC < col; curC++)
    {
        int curMin = 9000;
        for(int curR = 0; curR < row; curR++)
        {
            if(curC == 0)
			{
                if(matrix[curR][curC] < curMin)
				{
					curMin = curR;
					curLoc[0] = curR;
					curLoc[1] = curC;
				}
			}
            else
			{
				
			}
        }
        path.push_back(curMin);
    }

    for(unsigned int i = 0; i < path.size(); i++)
    {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
}
