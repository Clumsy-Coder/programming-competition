//DONE
#include <iostream>

using namespace std;

int main()
{
    int cases = 0;
    cin >> cases;

    for(int i  = 0; i < cases; i++)
    {
        int l = 0;
        int w = 0;
        int h = 0;

        cin >> l >> w >> h;

        cout << "Case " << i + 1 << ": ";

        if(l <= 20 && w <= 20 && h <= 20)
        {
            cout << "good" << endl;
        }

        else
        {
            cout << "bad" << endl;
        }

    }

    return 0;
}
