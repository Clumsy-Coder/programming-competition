//DONE

/*
    Use recursive backtracking with bitset
*/

#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int n = 0;
int answer = 0;
char board[14][14];
void solve(int col);
bitset<15> row, leftDiagonal, rightDiagonal;
int main()
{
    int cases = 0;
    while(cin >> n && (n && ++cases))
    {
        cin.ignore();
        answer = 0;
        for(int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);

            for(int j = 0; j < line.size(); j++)
            {
                board[i][j] = line[j];
            }
        }
        solve(0);
        cout << "Case " << cases << ": " << answer << endl;
    }
}

void solve(int col)
{
    if(col == n)
    {
        answer++;
        return;
    }
    else
    {
        for(int curRow = 0; curRow < n; curRow++)
        {
            //board[curRow][col] != '*'     : ignore the bad spots
            //!row[curRow]                  : if there's no queen on this row
            //!leftDiagonal[curRow - col]   : if there's no queen on the left slope. Using the idea of similar triangles
            //!rightDiagonal[curRow + col]  : if there's no queen on the right slope. Using the idea of similar triangles

            //similar triangles idea: 
            //imagine the board and the queen in a coordinate system, you can use a slope to determine if the current queen
            //and the next queen in the diagonal (left or right) are getting in the way (same path) if they have the same slope.
            //you don't need to calculate the hypotenuse, using the x and y values works.
            //
            //since it's recursing, the bitset is keeping track of the previous values and can be used to do a check, 
            //making the checks more restrictive since the chance of placing a queen is reduced.
            //
            //after checking all the possible combinations in that current state, reset the value that was recently 
            //modified so the next iteration can use it.
            if(board[curRow][col] != '*' && !row[curRow] && !leftDiagonal[curRow - col] && !rightDiagonal[curRow + col])
            {
                //add a queen at the position and recurse with that information for the next queen
                row[curRow] = leftDiagonal[curRow - col] = rightDiagonal[curRow + col] = true;
                solve(col + 1);
                //remove the queen at the position so the queen in the next row can be evaluated.
                row[curRow] = leftDiagonal[curRow - col] = rightDiagonal[curRow + col] = false;
            }
        }
    }
}
