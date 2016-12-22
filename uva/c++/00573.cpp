//DONE
#include <iostream>

using namespace std;

int main()
{
    double h, u, d, f;
    while(cin >> h >> u >> d >> f && h)
    {
        double totalDist = 0;
        long long days = 0;
        double curU = u;
        double distClimbedPerDay = u * (f / 100);
        do
        {
            days++;
            totalDist += curU;
            if(totalDist > h)
            {
                break;
            }
            totalDist -= d;
            if(totalDist < 0)
            {
                break;
            }
            curU -= distClimbedPerDay;
            if(curU < 0)
            {
                curU = 0;
            }

        } while(true);
        (totalDist > 0) ? cout << "success on day " << days << endl :
                          cout << "failure on day " << days << endl;
    }
}
