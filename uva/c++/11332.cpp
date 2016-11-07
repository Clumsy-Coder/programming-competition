//DONE
#include <iostream>

using namespace std;

int main()
{
    long long int n;
    int t;

    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }

        t = 0;
        while(true)
        {
            while(n != 0)
            {
                t = t + (n % 10);
                n = n / 10;
            }

            if(t / 10 == 0)
            {
                break;
            }
            else
            {
                n = t;
                t = 0;
            }
        }

        cout << t << endl;
    }

    return 0;
}
