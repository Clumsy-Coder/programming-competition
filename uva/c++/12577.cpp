//DONE
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string value;
    int caseNum = 1;
    while(cin >> value && value != "*")
    {
        if(value == "Hajj")
        {
            cout << "Case " << caseNum++ << ": Hajj-e-Akbar" << endl;
        }

        else if(value == "Umrah")
        {
            cout << "Case " << caseNum++ << ": Hajj-e-Asghar" << endl;
        }
    }

    return 0;
}
