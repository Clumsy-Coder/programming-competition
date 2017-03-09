#include <iostream>
#include <queue>

using namespace std;

const int dirX [] = {0 , 1, 0, -1};
const int dirY [] = {-1, 0, 1, 0 };

void readInput();

int numRow, numCol;

struct node
{
    int x, y;
    int colour; //0 = green, 1 = black, 2 = red, 3 = blue, 4 = white
    int time;
    int dir; //0 = north, 1 = east, 2 = south, 3 = west

    node() {}
    node(int curX, int curY, int curColour, int curTime, int curDir)
    {
        x = curX; y = curY;
        colour = curColour;
        time = curTime;
        dir = curDir;
    }

    node turn(int direction)
    {
        return node( x, y,                           //x and y
                     (dir + 1 + direction * 2) % 4,  //direction
                     colour,                              //colour
                     time + 1);                         //time
    }

    node moveForward()
    {
        return node( x + dirY[dir], y + dirX[dir],  //x and y
                     dir,                       //direction
                     (colour + 1) % 5,          //colour
                     time + 1);                 //time
    }

};

int status [30][30][5][5]; //[x][y][dir][colour]
char matrix [30][30];
node start, finish;

void print();
void solve();

int main()
{
    int cases = 1;
    while(cin >> numRow >> numCol && (numRow && numCol))
    {
        readInput();
        // print();
        cout << "Case #" << cases++ << endl;
        if(cases > 1)cout << endl;
    }
}

void readInput()
{
    for(int i = 0; i < numRow; i++)
    {
        for(int j = 0; j < numCol; j++)
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

void print()
{
    for(int i = 0; i < numRow; i++)
    {
        for(int j = 0; j < numCol; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    cout << "start x: " << start.x << "\t" << "start y: " << start.y << endl;
    cout << "finish x: " << finish.x << "\t" << "finish y: " << finish.y << endl;
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
        //ignore if current grid is #
        if(matrix[parent.x][parent.y] == '#') {continue;}
        //ignore if already visited
        if(status[parent.x][parent.y][parent.dir][parent.colour]) {continue;}
        //mark current coordinate as visited
        status[parent.x][parent.y][parent.dir][parent.colour] = 1;
        if (!(
                (parent.x + dirY[parent.dir] < 1) ||         //
                (parent.x + dirY[parent.dir] > numRow) ||    //if
                (parent.y + dirX[parent.dir] < 1) ||
                (parent.y + dirX[parent.dir] > numCol)))
        {
            continue;
        }


    }

    (answer.time != 0) ? cout << "minimum time = " << answer.time << " sec\n" :
                       cout << "destination not reachable\n";

}
