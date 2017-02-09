//DONE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <long long> a;
    for(long long x = 0; cin >> x;)
    {
        a.push_back(x);
        sort(a.begin(), a.end());
        if(a.size() % 2 == 1) //if there's odd number of elements in thr array
        {
            cout << a[a.size() / 2] << endl;
        }
        else
        {
            cout << (a[a.size() / 2] + a[(a.size() / 2) - 1]) / 2 << endl;
        }
    }
}
