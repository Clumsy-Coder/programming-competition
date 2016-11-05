#include <iostream>
#include <string>

using namespace std;

int main()
{
    string value;

    int caseNum = 1;
    while(cin >> value)
    {
        if(value == "#")
        {
            break;
        }

        cout << "Case " << caseNum++ << ": ";
        if(value == "HELLO")
        {
            cout << "ENGLISH" << endl;
        }

        else if(value == "HOLA")
        {
            cout << "SPANISH" << endl;
        }

        else if(value == "HALLO")
        {
            cout << "GERMAN" << endl;
        }

        else if(value == "BONJOUR")
        {
            cout << "FRENCH" << endl;
        }

        else if(value == "CIAO")
        {
            cout << "ITALIAN" << endl;
        }

        else if(value == "ZDRAVSTVUJTE")
        {
            cout << "RUSSIAN" << endl;
        }

        else
        {
            cout << "UNKNOWN" << endl;
        }
    }

    return 0;
}
