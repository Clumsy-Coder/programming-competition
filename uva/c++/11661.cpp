//DONE
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    long long  len;
    while(cin >>  len &&  len)
    {
        string s;
        cin >> s;
        long long rInd = -len;
        long long dInd = -len;
        // long long zInd = -len;
        long long answer = len;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'Z')
            {
                answer = 0;
                break;
            }
            else if(s[i] == 'D')
            {
                answer = min(answer, i - rInd);
                dInd = i;
            }
            else if(s[i] == 'R')
            {
                answer = min(answer, i - dInd);
                rInd = i;
            }
        }
        cout << answer << endl;
    }
}
