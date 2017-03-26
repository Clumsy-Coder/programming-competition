#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    int row, col;
    int dir;           //0 = north, 1 = east, 2 = south, 3 = west
    const int dirX [4] = { -1, 0, +1, 0 };
    const int dirY [4] = { 0, +1, 0, -1 };

    node(){row = col = dir = 0;}

    node(int curRow, int curCol, int curDir = 0)
    {
        row = curRow;
        col = curCol;
        dir = curDir;
    }

    node turn(int direction)
    {
        return node(row, col,                   //row and column
                    (dir + direction) % 4);     //direction
    }

    node move()
    {
        return node(row + dirX[dir],            //row
                    col + dirY[dir],            //column
                    dir);                       //direction
    }
};

bool status [1002][1002][5];
char grid[1002][1002];
int numRow, numCol;
unsigned long long mod = 0;
// long long numPossiblePaths = 0;
const int LEFT = 1;
const int RIGHT = 3;
const string direction = "NESW"; //north, east, south and west;
int cases = 1;
node start, finish;

void readInput();
long long solve();

void print()
{
    for(int curRow = 1; curRow <= numRow; curRow++)
    {
        for(int curCol = 1; curCol <= numCol; curCol++)
        {
            cout << grid[curRow][curCol];
        }
        cout << endl;
    }

    cout << "start: row: " << start.row << "\tcol: " << start.col << "\tdir: " << direction[start.dir] << endl;;
    cout << "end: row: " << finish.row << "\tcol: " << finish.col << endl;
}

int main()
{
    while(std::cin >> numRow >> numCol >> mod && (numRow && numCol && mod))
    {
        readInput();
        long long ans = solve();
        if(ans == 0)
        {
            cout << "Case " << cases++ << ": " << mod << " -1" << endl;
        }
        else
        {
            cout << "Case " << cases++ << ": " << mod << " " << ans % mod << endl;
        }
        // cout << "---------------------" << endl;
    }
}

void readInput()
{
    // numPossiblePaths = 0;
    memset(status, false, sizeof(status));
    memset(grid, '*', sizeof(grid));

    for(int curRow = 1; curRow <= numRow; curRow++)
    {
        for(int curCol = 1; curCol <= numCol; curCol++)
        {
            cin >> grid[curRow][curCol];
        }
    }

    cin >> start.row >> start.col;
    cin >> finish.row >> finish.col;

    char startDir; cin >> startDir;
    start.dir = find(direction.begin(), direction.end(), startDir) - direction.begin();
    // print();

}

long long solve()
{
    queue <node> bfs;
    bfs.push(start);

    long long numPossiblePaths = 0;

    while(!bfs.empty())
    {
        node curNode = bfs.front(); bfs.pop();

        //check if the node is at the finish line
        if(start.row == finish.row && start.col == finish.col)
        {
            numPossiblePaths++;
            continue;
            // return curNode.time;
        }

        //check if the current position is a # or
        //i've been here before, then ignore
        if(grid[curNode.row][curNode.col] == '*' ||
           status[curNode.row][curNode.col][curNode.dir])
        {
            continue;
        }

        //mark the current state is been visited
        status[curNode.row][curNode.col][curNode.dir] = true;

        //turn and move
        bfs.push(curNode.turn(LEFT));
        bfs.push(curNode.turn(RIGHT));
        bfs.push(curNode.move());
    }

    return numPossiblePaths;
}
