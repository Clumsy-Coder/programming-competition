#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int row, col;
const int MAX_ROW = 10;
const int MAX_COL = 100;
int matrix [MAX_ROW][MAX_COL];
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

            matrix[curR][curC] = matrix[curR][curC] + min({left, up, down});
        }
    }

    // print();
}

void backtrack()
{
    // vector<int> path;
    // int curLoc [] = {0, 0};
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
		//up. if curR = 0, then wrap around to the bottom. curR = row - 1
		int up = matrix[(index + row - 1) % row][i + 1];
		//down. if curR = row - 1, then wrap around to the top, curR = 0
		int down = matrix[(index + 1) % row][i + 1];

		auto temp = min({pair<int, int>(right, index), 
						 pair<int, int>(up, (index + row - 1) % row), 
						 pair<int, int>(down, (index + 1) % row)});
		index = temp.second;

    }

    cout << endl;
    cout << distance << endl;

    return;



   //  for(int curC = 0; curC < col; )
   //  {
   //      for(int curR = 0; curR < row; curR++)
   //      {
   //          if(curC == 0)
			// {
   //              if(matrix[curR][curC] < matrix[curLoc[0]][curLoc[1]])
			// 	{
			// 		curLoc[0] = curR;
			// 		curLoc[1] = curC;
			// 	}
			// }
   //          else
			// {
			// 	int right = matrix[curLoc[0]] [curLoc[1] + 1];
			// 	//up. if curR = 0, then wrap around to the bottom. curR = row - 1
			// 	int up = matrix[(curLoc[0] + row - 1) % row][curLoc[1] + 1];
			// 	//down. if curR = row - 1, then wrap around to the top, curR = 0
			// 	int down = matrix[(curLoc[0] + 1) % row][curLoc[1] + 1];

			// 	auto temp = min({pair<int, int>(right, curLoc[0]), 
			// 					 pair<int, int>(up, (curLoc[0] + row - 1) % row), 
			// 					 pair<int, int>(down, (curLoc[0] + 1) % row)});

			// 	cout << "right: " << right << endl;
			// 	cout << "up: " << up << endl;
			// 	cout << "down: " << down << endl;
			// 	cout << "temp: " << temp.first << endl;

			// 	//temp.second == curLoc[0] used for tie breaker
			// 	if(temp.first == right && temp.second == curLoc[0])
			// 	{
			// 		curLoc[1] = curLoc[1] + 1;
			// 		cout << "right\n\n";
			// 	}
			// 	else if(temp.first == up)
			// 	{
			// 		curLoc[0] = (curLoc[0] + row - 1) % row;
			// 		curLoc[1] = curLoc[1] + 1;
			// 		cout << "up\n\n";
			// 	}
			// 	else if(temp.first == down)
			// 	{
			// 		curLoc[0] = (curLoc[0] + 1) % row;
			// 		curLoc[1] = curLoc[1] + 1;
			// 		cout << "down\n\n";
			// 	}
			// 	curC = curLoc[1];
			// 	path.push_back(curLoc[0]);
			// }

			// if(curR == row - 1 && curC == 0)
			// {
			// 	path.push_back(curLoc[0]);
			// 	curC = curLoc[1] + 1;
			// }
   //      }
        
   //  }

   //  for(unsigned int i = 0; i < path.size(); i++)
   //  {
   //      cout << path[i] + 1 << " ";
   //  }
   //  cout << endl << matrix[path[0]][0] << endl;
   //  // cout << "----------\n\n";
}
