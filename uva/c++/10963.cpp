//DONE
#include <iostream>

using namespace std;

int main()
{
    int cases = 0;
    cin >> cases;

    int first;
    int second;

    while(cases--)
    {
        int cols;
        cin >> cols;
        bool mergeable = true;

        cin >> first >> second;
        int d = first - second;

        for(int i = 0; i < cols - 1; i++)
        {
            cin >> first >> second;
            if(d != first - second)
            {
                mergeable = false;
            }
        }

        (mergeable) ? cout << "yes" << endl : cout << "no" << endl;
        if(cases) cout << endl;
    }

    return 0;
}
