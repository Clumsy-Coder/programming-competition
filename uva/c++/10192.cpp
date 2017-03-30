//DONE
/*
    Use longest common subsequence to calculate the answer.
*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

long long cities[101][101];

long long solve(const string &city1, const string &city2);

int main()
{
    int cases = 1;
    string city1, city2;
    while(getline(cin, city1) && city1[0] != '#')
    {
        getline(cin, city2);
        cout << "Case #" << cases++ << ": you can visit at most " << solve(city1, city2) << " cities." << endl;
    }
}

long long solve(const string &city1, const string &city2)
{
    fill(cities[0], cities[100] + 101, 0);

    for(int i = 1; i <= city1.size(); i++)
    {
        for(int k = 1; k <= city2.size(); k++)
        {
            if (city1[i - 1] == city2[k - 1])
            {
				cities[i][k] = cities[i - 1][k - 1] + 1;
			}

            else if (cities[i - 1][k] >= cities[i][k - 1])
            {
				cities[i][k] = cities[i - 1][k];
			}

            else
            {
				cities[i][k] = cities[i][k - 1];
			}
        }
    }
    return cities[city1.size()][city2.size()];
}
