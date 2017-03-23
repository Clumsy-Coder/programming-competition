//DONE
/*
    Solve using Catalan numbers and dynamic programming
*/
#include <iostream>
#include <algorithm>

using namespace std;

long long solve(int pills, long long *array);

int main()
{
    long long array [31]; fill(array, array + 31, -1);
    int pills;
    while(cin >> pills && pills)
    {
        cout << solve(pills, array) << endl;
    }
}

long long solve(int pills, long long *array)
{
    if(array[pills] != -1)
    {
        return array[pills];
    }

    long long ans = 0;
    if(pills == 0) ans = 1;
    for(int i = 1; i <= pills; i++)
        ans += solve(i - 1, array) * solve(pills - i, array);
    return array[pills] = ans;
}
