//DONE. AdHoc
//while there's input
//  return the absolute value of the difference between two valus.

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

string line;
int main()
{
    while(getline(cin, line) && line.length())
    {
        stringstream stringStream(line);
        long long first;
        long long second;
        stringStream >> first >> second;

        cout << abs(first - second) << endl;


    }

    return 0;
}
