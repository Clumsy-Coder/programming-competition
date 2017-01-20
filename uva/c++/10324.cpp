//DONE
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    int cases = 1;
    while(cin >> line && line.size() > 0)
    {
        cout << "Case " << cases++ << ":" << endl;
        int loops;
        cin >> loops;
        while(loops--)
        {
            int x, y;
            cin >> x >> y;
            bool answer = true;
            for(int i = min(x, y); i < max(x, y); i++)
            {
                if(line[i] != line[i + 1])
                {
                    answer = false;
                    break;
                }
            }
            (answer) ? cout << "Yes" << endl: cout << "No" << endl;
        }
    }
}
