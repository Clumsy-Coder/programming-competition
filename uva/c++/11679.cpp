//DONE
#include <iostream>

using namespace std;

int main()
{
    int b;
    int n;
    int banks[21];
    while(cin >> b >> n && (b || n))
    {
        for(int i = 0; i < b; i++)
        {
            cin >> banks[i];
        }

        while(n--)
        {
            int d;
            int c;
            int v;
            cin >> d >> c >> v;
            banks[d - 1] -= v;
            banks[c - 1] += v;
        }

        bool pass = true; //if all the values in the bank[] is >= 0, then there's no bailout
        for(int i = 0; i < b; i++)
        {
            if(banks[i] < 0)
            {
                pass = false;
            }
        }
        
        (pass) ? cout << "S" << endl : cout << "N" << endl;
    }
}
