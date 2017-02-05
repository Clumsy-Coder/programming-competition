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
bitset<30> row, leftDiagonal, rightDiagonal;
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
            if(board[curRow][col] != '*' &&
               !row[curRow] &&
               !leftDiagonal[curRow - col + n - 1] &&
               !rightDiagonal[curRow + col])
            {
                row[curRow] = true;
                leftDiagonal[curRow - col + n - 1] = true;
                rightDiagonal[curRow + col] = true;
                solve(col + 1);
                row[curRow] = false;
                leftDiagonal[curRow - col + n - 1] = false;
                rightDiagonal[curRow + col] = false;
            }
        }
    }
}
