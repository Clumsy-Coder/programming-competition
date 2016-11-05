//DONE
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        string value;
        cin >> value;

        if(value.size() == 5)
        {
            cout << 3 << endl;
        }

        else
        {
            int count = 0;
            if(value[0] == 't') count++;
            if(value[1] == 'w') count++;
            if(value[2] == 'o') count++;

            if(count >= 2)
            {
                cout << 2 << endl;
            }

            else
            {
                cout << 1 << endl;
            }
        }

    }

    return 0;
}
