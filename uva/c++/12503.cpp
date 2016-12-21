//DONE
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int n;
        cin >> n;

        int answer = 0;
        vector <int> cmds;
        while(n--)
        {
            string line;
            cin >> line;
            if(line == "LEFT")
            {
                answer--;
                cmds.push_back(-1);
            }
            else if(line == "RIGHT")
            {
                answer++;
                cmds.push_back(1);
            }
            else if(line == "SAME")
            {
                cin >> line;
                int x;
                cin >> x;
                answer += cmds[x - 1];
                cmds.push_back(cmds[x - 1]);
            }
        }
        cout << answer << endl;
    }
}
