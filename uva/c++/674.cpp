//DONE
/*
    Use Bottom up Dynamic Programming technique.
    Base case is for 0 cents.
    generate the rest
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 7490;
int coins [MAX] = {1};     //base case from 0 cents
const int DENOMINATIONS [] = {1, 5, 10, 25, 50};
int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int k = DENOMINATIONS[i]; k < MAX; k++)
        {
            coins[k] += coins[k - DENOMINATIONS[i]];
        }
    }
    int value;
    while(cin >> value)
    {
        cout << coins[value] << endl;
    }
}
