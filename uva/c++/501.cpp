#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        cin.ignore();
        int numAdd, numGet;
        cin >> numAdd >> numGet;
        vector<int> addQueue(numAdd);
        multiset<int> getQueue;
        for(int i = 0; i < numAdd; i++)
        {
            cin >> addQueue[i];
        }

        for(int i = 0, curAdd = 0; i < numGet; i++)
        {
            int temp;
            cin >> temp;

            //add to getQueue if not enough elements
            while(getQueue.size() < temp && getQueue.size() - temp)
            {
                getQueue.insert(addQueue[curAdd++]);
            }

            auto iterator = getQueue.begin();
            for(int j = 0; j < i; j++)
            {
                iterator++;
            }
            cout << *iterator << endl;
        }
        if(cases){cout << endl;}
    }
}
