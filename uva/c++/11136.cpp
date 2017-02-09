//DONE

/*
    use multiset because there might be duplicate values AND it sorts the key automatically

*/

#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

int main()
{
    int cases;
    while(cin >> cases && cases)
    {
        long long total = 0;
        multiset<int> list;
        for(int curCase = 0; curCase < cases; curCase++)
        {
            int numBill;
            cin >> numBill;
            for(int i = 0; i < numBill; i++)
            {
                int temp;
                cin >> temp;
                list.insert(temp);
            }

            total += abs(*list.begin() - *--list.end());
            list.erase(list.begin());
            list.erase(--list.end());
        }
        cout << total << endl;
    }
}
