#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int dirX [] = {-1, 0, 1, 0 };
const int dirY [] = {0 , 1, 0, -1};
const int RIGHT = 1;
const int LEFT = 3;
bool status [30][30][5][5]; //[x][y][dir][colour]

void readInput();

int numRow, numCol;

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
        return node( x + dirX[dir], y + dirY[dir],  //x and y
                     dir,                           //direction
                     (colour + 1) % 5,              //colour
                     time + 1);                     //time
    }

    bool valid()
    {
        return (x + dirX[dir] < numRow &&  x + dirX[dir] >= 0) && 
               (y + dirY[dir] < numCol && y + dirY[dir] >= 0);

    }

};


char matrix [27][27];
node start, finish;
int cases = 1;

void print();
void solve();

int main()
{
    
    while(cin >> numRow >> numCol && (numRow && numCol))
    {
        if(cases > 1)cout << endl;
        readInput();
        solve();
        // cout << "Case #" << cases++ << endl;
    }
}

void readInput()
{
    memset(status, false, sizeof(status));
    memset(matrix, '#', sizeof(matrix));
    for(int i = 1; i < numRow + 1; i++)
    {
        for(int j = 1; j < numCol + 1; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'S')
            {
                start.x = i;
                start.y = j;
                start.colour = 0;
            }
            if(matrix[i][j] == 'T')
            {
                finish.x = i;
                finish.y = j;
                finish.colour = 0;
            }
        }
    }
}

void solve()
{
    queue <node> bfs;
    bfs.push(start);
    node answer;

    while(!bfs.empty())
    {
        node parent = bfs.front(); bfs.pop();

        //check if the node is at the finish
        if(parent.x == finish.x && parent.y == finish.y && parent.colour == finish.colour)
        {
            answer = parent;
            break;
        }
        // //ignore if current grid location is #
        // if(matrix[parent.x][parent.y] == '#') {continue;}
        // //ignore if already visited
        // if(status[parent.x][parent.y][parent.dir][parent.colour]) {continue;}
        // //if it's in bounds
        // if (!parent.valid()){continue;}

        if( matrix[parent.x][parent.y] == '#' || 
            status[parent.x][parent.y][parent.dir][parent.colour] ||
            !parent.valid())
        {
            continue;
        }

        //mark current coordinate as visited
        status[parent.x][parent.y][parent.dir][parent.colour] = true;
        //turn right
        bfs.push(parent.turn(RIGHT));
        //turn left
        bfs.push(parent.turn(LEFT));
        //move foreward
        bfs.push(parent.moveForward());

    }

    cout << "Case #" << cases++ << endl;
    (answer.time != 0) ? cout << "minimum time = " << answer.time << " sec\n" :
                       cout << "destination not reachable\n";
}
