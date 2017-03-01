//DONE
/*
    Ad-hoc problem
    total: checks the current streak. If it's below 0, you start at 0
        set it to maxStreak IF it's higher than maxStreak
    maxStreak: contains the highest 'total' value
    find the maxStreak
*/

#include <iostream>

using namespace std;

int main()
{
    int numSequence;
    while(cin >> numSequence && numSequence)
    {
        int total = 0;
        int maxStreak = -10000;
        for (int i = 0; i < numSequence; i++)
        {
            int temp;
            cin >> temp;
            total += temp;
            //if new total is greater than maxStreak, then it's the new maxStreak
            if(total > maxStreak)
            {
                maxStreak = total;
            }
            //if the total is below 0. Restart the total to 0 (current streak)
            if(total < 0)
            {
                total = 0;
            }
        }
        //print the answer
        (maxStreak > 0) ? cout << "The maximum winning streak is " << maxStreak << "." << endl :
                          cout << "Losing streak." << endl;
    }
}
