#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <cstdlib>

using namespace std;

void solve();

int main()
{
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        cin.ignore();
        solve();
        cout << endl;

    }
}

void solve()
{
    int numAdd, numGet;
    cin >> numAdd >> numGet;
    queue<int> addQueue;
    priority_queue<int, vector<int>, greater<int> > getQueue;
    for(int i = 0; i < numAdd; i++)
    {
        int temp;
        cin >> temp;
        addQueue.push(temp);
    }

    for(int i = 0; i < numGet; i++)
    {
        int temp;
        cin >> temp;

        if(getQueue.size() < temp)
        {
            int diff = abs((int)getQueue.size() - temp);
            for(int i = 0; i < diff; i++)
            {
                getQueue.push(addQueue.front());
                addQueue.pop();
            }
        }

        priority_queue<int, vector<int>, greater<int> > copyQ(getQueue);
        for(int j = 0; j < i; j++)
        {
            copyQ.pop();
        }
        cout << copyQ.top() << endl;

    }
}
