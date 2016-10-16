#include <iostream>

using namespace std;

int const bottleCal = 400;

int main()
{
    int cases = 0;
    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        int value = 0;
        cin >> value;

        if(value % bottleCal != 0)
        {
            cout << value / bottleCal + 1 << endl;

        }

        else
        {
            cout << value / bottleCal << endl;

        }

    }

    return 0;
}
