//DONE
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int curCase = 0; curCase < cases; curCase++)
    {
        int n;
        cin >> n;
        int answer = -1;
        while(n--)
        {
            int cur;
            cin >> cur;
            answer = max(answer, cur);
        }

        cout << "Case " << curCase + 1 << ": " << answer << endl;
    }
}
