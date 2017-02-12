//DONE
#include <iostream>

using namespace std;

int main()
{
    int numSets;
    int allNums [1000 + 1];
    while(cin >> numSets && numSets)
    {
        for(int i = 0; i < numSets; i++)
        {
            cin >> allNums[i];
        }
        //used to indicate if there should be space after a non zero value was entered.
        //if there no non zero values, then just display a 0;
        bool addSpace = false;
        for(int i = 0, curVal = allNums[i]; i < numSets; i++, curVal = allNums[i])
        {
            if(curVal != 0)
            {
                if(addSpace) //if there's more elements to display
                {
                    cout << " ";
                }
                addSpace = true;
                cout << curVal;
            }
        }
        if(!addSpace) //if there were no non zero value in the array.
        {
            cout << "0";
        }
        cout << endl;
    }
}
