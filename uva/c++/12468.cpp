//DONE
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;

    while(cin >> a >> b)
    {
        if (a < 0 && b < 0){break;}
        int answer = abs(a - b);
        cout << ((answer > 50) ? 100 - answer : answer) << endl;
    }
}
