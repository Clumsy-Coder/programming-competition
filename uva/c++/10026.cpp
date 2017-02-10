#include <iostream>
#include <queue>

using namespace std;

struct job
{
    int id;
    int time;
    int fine;
};

class ComparisionClass
{
    public:
        bool operator() (job &job1, job &job2)
        {
            if((job1.time * job2.fine) == (job2.time * job1.fine) ||
               (job1.time * job2.fine) < (job2.time * job1.fine))
            {
                return false;
            }
            else if((job1.time * job2.fine) < (job2.time * job1.fine))
            {
                return true;
            }
            return (job1.time * job2.fine) != (job2.time * job1.fine);
        }
};

priority_queue<job, vector<job>, ComparisionClass> allJobs;

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        // allJobs.clear();
        int numJobs;
        cin >> numJobs;
        for(int i = 0; i < numJobs; i++)
        {
            job curJob; curJob.id = i + 1;
            cin >> curJob.time >> curJob.fine;
            // cout << curJob.time << " " << curJob.fine << endl;
            allJobs.push(curJob);
        }

        // cout << allJobs.top().id << " "; allJobs.pop();
        while(!allJobs.empty())
        {
            cout << allJobs.top().id;
            allJobs.pop();
            if(!allJobs.empty()) cout << " ";
        }
        cout << endl;
        if(cases){cout << endl;}
    }
}
