//DONE
#include <iostream>

using namespace std;

int main()
{
    int cases = 0;
    cin >> cases;
    long long total = 0;
    while(cases--)
    {
        string cmd;
        long long value = 0;

        cin >> cmd;

        if(cmd == "donate")
        {
            cin >> value;
            total += value;
        }

        else if(cmd == "report")
        {
            cout << total << endl;
        }
    }

    return 0;
}
