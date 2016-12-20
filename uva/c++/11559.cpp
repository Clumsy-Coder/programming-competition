//DONE
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int part;
    int budget;
    int hotels;
    int weeks;
    int answer;
    while(cin >> part >> budget >> hotels >> weeks)
    {
        answer = budget + 1;

        for(int i = 0; i < hotels; i++)
        {
            int price;
            cin >> price;
            int cap = 0;

            for(int j = 0; j < weeks; j++)
            {
                int available;
                cin >> available;
                cap = max(cap, available);
            }

            if(cap >= part)
            {
                answer = min(answer, part * price);
            }
        }

        (answer == budget + 1) ? cout << "stay home\n" : cout << answer << endl ;
    }
}
