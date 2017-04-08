/*
    Problem type: Graph
    Data structure: struct, 2D, 3D array and queue
    Algorithm: BFS
    Summary: visited each node ONLY once and append the 
             values from the previous path until you reached 
             the destination. mod the values to prevent overflow
             Only choose the smaller paths.

*/

#include <iostream>
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


void readInput();
void solve();
void printAns();
void addState(queue <node> &bfs, const node &curNode, const node &nextNode);

const int LEFT = 1, RIGHT = 3;
const string direction = "NESW"; //north, east, south and west;
node start, finish;
long long numRows, numCols, mod, cases = 1;
char grid [1002][1002];
long long dist [1002][1002][5]; // only contains the shortest path [max rows][max columns][4 directions + 1]
long long paths[1002][1002][5]; // contains # of ways to get from point A to point B

int main()
{
    while(cin >> numRows >> numCols >> mod && (numRows && numCols && mod))
    {
        readInput();
        solve();
        printAns();
    }
}

void readInput()
{
    // clear the data
    fill(grid[0], grid[1001] + 1002, '*');
    fill(dist[0][0], dist[1001][1001] + 5, -1);
    fill(paths[0][0], paths[1001][1001] + 5, 0);

    for(int i = 1; i <= numRows; i++)
        for(int k = 1; k <= numCols; k++)
            cin >> grid[i][k];

    cin >> start.row>> start.col; start.row++; start.col++;
    cin >> finish.row >> finish.col; finish.row++; finish.col++;
    char startDir; cin >> startDir;
    start.dir = find(direction.begin(), direction.end(), startDir) - direction.begin();
}

// use bfs to go through the grid
void solve()
{
    queue <node> bfs;
    bfs.push(start);
    paths[start.row][start.col][start.dir] = 1;

    while(!bfs.empty())
    {
        node curNode = bfs.front(); bfs.pop();

        // reached the destination
        if( curNode.row == finish.row && 
            curNode.col == finish.col)
        {
            break;
        }

        if( grid[curNode.row][curNode.col] != '*')
        {
            addState(bfs, curNode, curNode.move());
        }

        addState(bfs, curNode, curNode.turn(LEFT));
        addState(bfs, curNode, curNode.turn(RIGHT));
    }
}

void addState(queue <node> &bfs, const node &curNode, const node &nextNode)
{
    long long curDist = dist[curNode.row][curNode.col][curNode.dir];
    long long nextDist = dist[nextNode.row][nextNode.col][nextNode.dir];
    long long curPaths = paths[curNode.row][curNode.col][curNode.dir];
    // check the nextNode distance is visited AND is smaller than 
    // the smallest distance recorded
    // ignore it since, we already been there
    if(nextDist >= 0 && nextDist < curDist + 1)
    {
        return;
    }
    // explore the ones that aren't visited
    if(nextDist < 0)
    {
        bfs.push(nextNode);
    }

    // add the distance, increment the paths and mod it so it doesn't overflow
    dist[nextNode.row][nextNode.col][nextNode.dir] = curDist + 1;
    paths[nextNode.row][nextNode.col][nextNode.dir] += curPaths;
    paths[nextNode.row][nextNode.col][nextNode.dir] %= mod;
    
}

void printAns()
{
    cout << "Case " << cases++ << ": " << mod << " ";

    long long answer = 0;
    bool ansFound = false;
    for(int i = 0; i < 4; i++)
    {
        answer += paths[finish.row][finish.col][i];
        if(dist[finish.row][finish.col][i] >= 0)
        {
            ansFound = true;
        }
    }

    if(ansFound || answer)
    {
        cout << (answer % mod) << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
}   