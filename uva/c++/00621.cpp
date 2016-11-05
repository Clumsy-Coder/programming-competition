//DONE
#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;

    while(cases--)
    {
        string value;
        cin >> value;

        //positive result
        if(value == "1" || value == "4" || value == "78")
        {
            cout << "+" << endl;
        }

        //negative result
        else if(value[value.size() - 1] == '5' &&
                value[value.size() - 2] == '3')
        {
            cout << "-" << endl;
        }

        //failed experiment
        else if(value[value.size() - 1] == '4' &&
                value[0] == '9')
        {
            cout << "*" << endl;
        }

        //incomplete experiment
        else if(value[0] == '1' &&
                value[1] == '9' &&
                value[2] == '0')
        {
            cout << "?" << endl;
        }
    }

    return 0;
}
