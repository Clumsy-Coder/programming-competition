//DONE
/*
    use vector for M values and to compute the answer, because accessing them is constant time.
        Getting the answer from getQueue is always constant, compared to
        multiset, or priority queue.
        Multiset and priority queue require O(n) to get the value that is between index 0 and size - 1
            That would take too long to pass the Uva judge.
    When inserting into getQueue, use lower_bound to find the position to be
    inserted in. This will end up causing the vector to sorted.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cases; cin >> cases;
    while(cases--)
    {
        cin.ignore();
        int numAdd, numGet; cin >> numAdd >> numGet;
        vector<int> addQueue(numAdd);
        vector<int> getQueue;
        for(int i = 0; i < numAdd; i++)
        {
            cin >> addQueue[i];
        }

        for(int i = 0, curAdd = 0; i < numGet; i++)
        {
            int temp; cin >> temp;
            //add to getQueue if not enough elements
            while(getQueue.size() < temp)
            {
                //use lower bound because it returns the index of the value closest to it.
                //  The first occurance of the value
                //the iterator value return is in 0 based.
                //this is self sorting when inserting to the vector
                //lower bound will always run on log n + 1 because it's self sorting.
                auto iterator = lower_bound(getQueue.begin(), getQueue.end(), addQueue[curAdd]);
                getQueue.insert(iterator, addQueue[curAdd++]);

            }
            cout << getQueue[i] << endl;
        }
        if(cases){cout << endl;}
    }
}
