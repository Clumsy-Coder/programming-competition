//DONE
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool check(int middle);
int numAP, numRes;
int resLoc[100000 + 2];
int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        cin >> numAP >> numRes;
        for(int i = 0; i < numRes; i++)
        {
            cin >> resLoc[i];
        }
        sort(resLoc, resLoc + numRes);

        //binary search the range
        int low = 0;
        // * 2 to avoid decimal value calc for middle. using a double would cause the answer to be rounded up
        //also int division can be tricky
        int high = 2 * (resLoc[numRes - 1] - resLoc[0] + 1);
        while(high > low)
        {
            int middle = (high + low) / 2;
            if(check(middle))
            {
                high = middle;
            }
            else
            {
                low = middle + 1;
            }
        }
        cout << fixed << setprecision(1) << high / 2.00 << endl;
    }
}

bool check(int middle)
{
    int numAP_used = 1;
    int range = resLoc[0] + middle;     //assign to the first house;
    for(int i = 0; i < numRes; i++)
    {
        if(resLoc[i] > range)
        {
            range = resLoc[i] + middle;     //move to the next house
            numAP_used++;
        }
    }
    //if the number of AP required are still under budget. Can't buy more than required
    return numAP_used <= numAP;
}
