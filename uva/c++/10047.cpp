//DONE
/*
    use bfs to find the best path to the finish.
    there will only be two answers for each cases (either the path is found or not).
        if the path is found
            the answer must match row, col, and the colour to the finish in order to complete the search.
    use a struct to define a node in the grid.
        each node will have row, col, colour, dir, time defined by default.
        you can either turn right or left or move foreward based on the current position and direction.
    keep searching in the grid until the path is found or not.
*/

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

struct node
{
    int row, col;
    int colour;     //0 = green, 1 = black, 2 = red, 3 = blue, 4 = white
    int dir;        //0 = north, 1 = east, 2 = south, 3 = west
    int time;

    const int dirX [4] = { -1, 0, +1, 0 };
    const int dirY [4] = { 0, +1, 0, -1 };

    node(){row = col = colour = dir = time = 0;}

    node(int curRow, int curCol, int curColour = 0, int curDir = 0, int curTime = 0)
    {
        row = curRow;
        col = curCol;
        colour = curColour;
        dir = curDir;
        time = curTime;
    }

    node turn(int direction)
    {
        return node(row, col,                   //row and column
                    colour,                     //colour
                    (dir + direction) % 4,      //direction
                    time + 1);                  //time
    }

    node move()
    {
        return node(row + dirX[dir],            //row
                    col + dirY[dir],            //column
                    (colour + 1) % 5,           //colour
                    dir,                        //direction
                    time + 1);                  //time
    }

};

bool status [30][30][5][5];         //[row][col][direction][colour]
char grid[30][30];
int numRow, numCol;
const int LEFT = 1;
const int RIGHT = 3;
node start;
int cases = 1;

void readInput();
int solve();

int main()
{
    while(cin >> numRow >> numCol && (numRow && numCol))
    {
        if(cases > 1) {cout << endl;}
        readInput();
        int answer = solve();
        cout << "Case #" << cases++ << endl;
        (answer != 0) ? cout << "minimum time = " <<  answer << " sec" << endl :
                        cout << "destination not reachable" << endl;
    }
}

void readInput()
{
    memset(status, false, sizeof(status));
    memset(grid, '#', sizeof(grid));

    for(int curRow = 1; curRow <= numRow; curRow++)
    {
        for(int curCol = 1; curCol <= numCol; curCol++)
        {
            cin >> grid[curRow][curCol];
            if(grid[curRow][curCol] == 'S')
            {
                start.row = curRow;
                start.col = curCol;
            }
        }
    }
}

int solve()
{
    queue <node> bfs;
    bfs.push(start);

    while(!bfs.empty())
    {
        node curNode = bfs.front(); bfs.pop();

        //check if the node is at the finish line
        if(grid[curNode.row][curNode.col] == 'T' && curNode.colour == 0)
        {
            return curNode.time;
        }

        //check if the current position is a # or
        //i've been here before, then ignore
        if(grid[curNode.row][curNode.col] == '#' ||
           status[curNode.row][curNode.col][curNode.dir][curNode.colour])
        {
            continue;
        }

        //mark the current state is been visited
        status[curNode.row][curNode.col][curNode.dir][curNode.colour] = true;

        //turn and move
        bfs.push(curNode.turn(LEFT));
        bfs.push(curNode.turn(RIGHT));
        bfs.push(curNode.move());
    }
    return 0;
}
