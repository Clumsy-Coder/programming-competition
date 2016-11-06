//done
#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    int n;

    while(cin >> x >> y >> n)
    {
        for(int i = 1; i <= n ; i++)
        {
            bool xDivisible = false;
            bool yDivisible = false;

            if(i % x == 0)
            {
                xDivisible = true;
            }
            if(i % y == 0)
            {
                yDivisible = true;
            }

            if(xDivisible && yDivisible)
            {
                cout << "FizzBuzz" << endl;
            }
            else if (xDivisible)
            {
                cout << "Fizz" << endl;
            }
            else if (yDivisible)
            {
                cout << "Buzz" << endl;
            }
            else
            {
                cout << i << endl;
            }

        }
    }

    return 0;
}
