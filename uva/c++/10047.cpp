#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int dirY [] = {-1, 0, 1, 0 };
const int dirX [] = {0 , 1, 0, -1};
const int RIGHT = 1;
const int LEFT = 3;
bool status [30][30][5][5]; //[x][y][dir][colour]
char matrix [27][27];
int cases = 1;
int numRow, numCol;
int solve();
void readInput();
void print();

struct node
{
    int x, y;
    int colour; //0 = green, 1 = black, 2 = red, 3 = blue, 4 = white
    int time;
    int dir; //0 = north, 1 = east, 2 = south, 3 = west

    node() {}
    node(int curX, int curY, int curColour=0, int curTime=0, int curDir=0)
    {
        x = curX; y = curY;
        colour = curColour;
        time = curTime;
        dir = curDir;
    }

    node turn(int direction)   //direction 1 = right, direction 3 = left
    {
        return node( x, y,                           //x and y
                     (dir + direction) % 4,          //direction
                     colour,                         //colour
                     time + 1);                      //time
    }

    node moveForward()
    {
        return node( x + dirY[dir], y + dirX[dir],  //x and y
                     dir,                           //direction
                     (colour + 1) % 5,              //colour
                     time + 1);                     //time
    }

    bool valid()
    {
        // return (x + dirX[dir] < numRow &&  x + dirX[dir] >= 0) && 
        //        (y + dirY[dir] < numCol && y + dirY[dir] >= 0);
        return ((x + dirY[dir] < 1) ||  (x + dirY[dir] > numRow) ||
               (y + dirX[dir] < 1) || (y + dirX[dir] > numCol));

    }

};

node start;
int main()
{
    while(cin >> numRow >> numCol && (numRow && numCol))
    {
        if(cases > 1)cout << endl;
        readInput();
        // print();
        int answer = solve();
        cout << "Case #" << cases++ << endl;
        (answer != 0) ? cout << "minimum time = " << answer << " sec\n" :
                       cout << "destination not reachable\n";
    }
}

void readInput()
{
    memset(status, false, sizeof(status));
    memset(matrix, '#', sizeof(matrix));
    for(int i = 1; i <= numRow; i++)
    {
        for(int j = 1; j <= numCol; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'S')
            {
                start = node(i, j, 0, 0, 0);
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
        //check if the node is at the finish
        // if(curNode.x == finish.x && curNode.y == finish.y && curNode.colour == finish.colour)
        if(matrix[curNode.x][curNode.y] == 'T' && curNode.colour == 0)
        {
            return curNode.time;
        }

        //ignore if current position is #, or
        //already visited or
        if( matrix[curNode.x][curNode.y] == '#' || 
            status[curNode.x][curNode.y][curNode.dir][curNode.colour])
        {
            continue; 
        }

        //mark current coordinate as visited
        status[curNode.x][curNode.y][curNode.dir][curNode.colour] = true;

        if(!curNode.valid())
        {
            bfs.push(curNode.moveForward());
        }
        bfs.push(curNode.turn(RIGHT));
        bfs.push(curNode.turn(LEFT));

    }
    return 0;
}

void print()
{
    for(int i = 0; i <= numRow + 1; i++)
    {
        for(int j = 0; j <= numCol + 1; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}