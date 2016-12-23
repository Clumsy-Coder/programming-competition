//DONE
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numReq; int numProp; int cases = 1;
    while(cin >> numReq >> numProp && (numReq && numProp))
    {
        double cost = 100000.0;
        int reqMet = 0;
        string name;
        for(int i = 0; i < numReq; i++) //ignore all the requirements.
        {
            string ignoreLine;
            cin.ignore();
            getline(cin, ignoreLine);
        }
        while(numProp--)
        {
            //the problem doesn't check which requirements were met.
            string propName; double curCost; int curReqMet;
            getline(cin, propName);
            cin >> curCost >> curReqMet;
            if(curReqMet > reqMet) //judge based on number of requirements met.
            {
                name = propName;
                reqMet = curReqMet;
                cost = curCost;
            }
            else if(reqMet == curReqMet && curCost < cost) //if the number of requirements are equal but the price is lower
            {
                name = propName;
                reqMet = curReqMet;
                cost = curCost;
            }
            for(int i = 0; i < curReqMet; i++) //ignore which requirements were met
            {
                string ignoreReq;
                cin.ignore();
                getline(cin, ignoreReq);
            }
        }
        if(cases > 1){cout << endl;}

        cout << "RFP #" << cases++ << endl;
        cout << name << endl;
    }
}
