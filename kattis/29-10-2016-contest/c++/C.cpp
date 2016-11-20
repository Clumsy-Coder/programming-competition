#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    long long entries;

    while(cin >> entries)
    {
        vector<long double> list;
        for(int i = 0; i < entries; i++)
        {
            string password;
            long double value;
            cin >> password >> value;

            list.push_back(value);
        }

        sort(list.begin(), list.end());
        reverse(list.begin(), list.end());

        long double answer = 0;
        for(long long i = 0; i < list.size(); i++)
        {
            answer += list[i] * (i + 1);

        }
        cout << std::setprecision(4);
        cout << std::fixed;
        cout << answer << endl;
    }
    return 0;
}
