//IN PROGRESS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int totalTime = 0;
vector<int> jobsList;
int cases = 0;
int jobs = 0;
int wood = 0;
int woodSize = 0;


int main()
{
    //int cases = 0;
    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        //int jobs;
        cin >> jobs;

        for(int k = 0; k < jobs; k++)
        {
            //int wood = 0;
            cin >> wood;

            for(int j = 0; j < wood; j++)
            {
                //int woodSize = 0;
                cin >> woodSize;

                jobsList.push_back(woodSize);

                if(wood > 1 && jobs == 1)
                {
                    totalTime += woodSize;
                }

            }

            if(jobs > 1)
            {

                if(k + 1 == jobs)
                {
                    sort(jobsList.begin(), jobsList.end());
                    //cout << "adding: " << jobsList[0] << endl;
                    totalTime += jobsList[0];
                    jobsList.clear();
                }
            }

        }

        cout << fixed << setprecision(10);
        if(jobs == 1)
        {
            cout << (double) totalTime << endl;

        }
        else
        {
            //cout << "i + 1: " << i + 1 << endl;
            //cout << "total time: " << totalTime << endl;

            cout << (double)totalTime / (i + 1) << endl;
        }
        jobsList.clear();

    }

    return 0;
}
