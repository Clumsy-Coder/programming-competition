//DONE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    cout << "Lumberjacks:" << endl;
    while(cases--)
    {
        vector<int> n(10);
        for(int i = 0; i < 10; i++)
        {
            cin >> n[i];
        }

        if(is_sorted(n.begin(), n.end()) ||
           is_sorted(n.begin(), n.end(),
           [](const int &a, const int &b) -> bool //checking if it's sorted in the descending order
                {
                    return a > b;
                }))
        {
            cout << "Ordered" << endl;
        }
        else
        {
            cout << "Unordered" << endl;
        }
    }
}
