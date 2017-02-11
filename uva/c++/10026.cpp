//DONE
#include <iostream>
#include <queue>

using namespace std;

struct job
{
    int id;
    int time;
    int fine;
    bool operator() (const job &job1, const job &job2)
    {
        if((job1.time * job2.fine) == (job2.time * job1.fine))
        {
            return job2.id < job1.id;
        }
        return (job1.time * job2.fine) > (job2.time * job1.fine);
    };
};

priority_queue<job, vector<job>, job> allJobs;

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int numJobs;
        cin >> numJobs;
        for(int i = 0; i < numJobs; i++)
        {
            job curJob; curJob.id = i + 1;
            cin >> curJob.time >> curJob.fine;
            allJobs.push(curJob);
        }
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
