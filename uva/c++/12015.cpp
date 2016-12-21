//DONE
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int curCase = 0; curCase < cases; curCase++)
    {
        cout << "Case #" << curCase + 1 << ":" << endl;

        string url[10];
        int relevance [10];
        int maxValue = -1;
        for(int i = 0; i < 10; i++)
        {
            cin >> url[i] >> relevance[i];
            maxValue = max(maxValue, relevance[i]);
        }

        for(int i = 0; i < 10; i++)
        {
            if(relevance[i] == maxValue)
            {
                cout << url[i] << endl;
            }
        }
    }
}
