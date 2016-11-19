#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        int walls = 0;
        cin >> walls;
        int high = 0;
        int low = 0;
        int curWall = 0;

        for(int j = 0; j < walls; j++)
        {

                int height = 0;
                cin >> height;

                if(j == 0){curWall = height; continue;}

                if(curWall < height){high++;}
                else if(curWall > height){low++;}

                curWall = height;

        }

        cout << "Case " << i + 1 << ": " << high << " " << low << endl;

    }

    return 0;
}
