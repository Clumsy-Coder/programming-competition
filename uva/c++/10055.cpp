//DONE
#include <iostream>

using namespace std;

int main()
{
    long long x, y;
    while(cin >> x >> y)
    {
        (x < y) ? cout << y - x << endl : cout << x - y << endl;
    }
}
