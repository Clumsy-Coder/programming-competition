//DONE
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    string curTime;
    while(getline(cin, curTime) && curTime != "0:00")
    {
        if(curTime.size() == 4)
        {
            curTime = "0" + curTime;
        }
        float hour = stoi(curTime.substr(0, 2));
        float minute = stoi(curTime.substr(3, 2));
        hour = ((hour * 30) + (minute / 2));
        minute = minute * 6;
        if(abs(hour - minute) > 180)
        {
            cout << fixed << setprecision(3) << (360 - abs(hour - minute)) << endl;
        }
        else
        {
            cout << fixed << setprecision(3) << abs(hour - minute) << endl;
        }
    }
}
