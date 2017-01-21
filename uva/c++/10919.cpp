//DONE
#include <iostream>

using namespace std;

bool find(int crs);

int k, m;
int courses [100];

int main()
{
    while(cin >> k >> m && k)
    {
        for(int i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            courses[i] = temp;
        }
        bool finished = true;
        for(int i = 0; i < m; i++)
        {
            int crs, req, crsMet = 0;
            cin >> crs >> req;
            for(int j = 0; j < crs; j++)
            {
                int curCrs;
                cin >> curCrs;
                if(find(curCrs))
                {
                    crsMet++;
                }
            }
            if(crsMet < req)
            {
                finished = false;
            }
        }
        (finished) ? cout << "yes" << endl : cout << "no" << endl;
    }
}
bool find(int crs)
{
    for(int i = 0; i < k; i++)
    {
        if(courses[i] == crs)
        {
            return true;
        }
    }
    return false;
}
