//DONE
#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int curCase = 0; curCase < cases; curCase++)
    {
        cout << "Case " << curCase + 1 << ": ";
        int calls;
        cin >> calls;

        int mile = 0;
        int juice = 0;
        for(int i = 0; i < calls; i++)
        {
            int call;
            cin >> call;

            mile += ((call / 30) * 10) + 10;
            juice += ((call / 60) * 15) + 15;

        }

        if(mile == juice){cout << "Mile Juice " << mile << endl;}
        else if(mile < juice){cout << "Mile " << mile << endl;}
        else{cout << "Juice " << juice << endl;}
    }
}
