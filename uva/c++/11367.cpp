//DONE
/*
    store the graph, fuel
    compute the distance using dijkstra algorithm
*/

#include <iostream>
#include <climits>      //to get the max int value
#include <queue>        //use priority queue for dijkstra algorithm
#include <algorithm>    //for calling std::fill
#include <vector>

using namespace std;

const int MAX_N = 1000, MAX_C = 100;

struct edges
{
    int city, fuelLevel, cost;
    edges(){}
    edges(int c, int f, int co)
    {
        city = c;
        fuelLevel = f;
        cost = co;
    }
    //comparision operator for dijkstra algorithm
    bool operator < (const edges &input) const
    {
        return cost > input.cost;
    }
};

int fuelCost [MAX_N + 1];
// edges graph [MAX_N + 1];
vector <edges> graph[MAX_N + 1];

void readInput();
void solve();
int dijkstra(int start, int end, int fuelCap);

int main()
{
    readInput();
    solve();
}

void readInput()
{
    int numCity, numRoad;
    cin >> numCity >> numRoad;
    for(int i = 0; i < numCity; i++)        //read the fuel cost
    {
        cin >> fuelCost[i];
    }

    for(int i = 0; i < numRoad; i++)        //read which city is connected
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].push_back(edges(end, 0, cost));
        graph[end].push_back(edges(start, 0, cost));
    }
}

void solve()
{
    int numQuery;
    cin >> numQuery;
    while(numQuery--)
    {
        int fuelCap, start, end;
        cin >> fuelCap >> start >> end;
        int answer = dijkstra(start, end, fuelCap);
        if(answer < INT_MAX)
        {
            cout << answer << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }
}

int dijkstra(int start, int end, int fuelCap)
{
    int distance [MAX_N + 1][MAX_C + 1];
    fill(distance[0], distance[MAX_N] + MAX_C + 1, INT_MAX);

    priority_queue <edges> pq;
    pq.push(edges(start, 0, 0));        //starting at 0 fuel and 0 cost to refuel (in terms of distance)
    distance[start][0] = 0;             //set the starting node distance to 0

    while(!pq.empty())
    {
        edges curEdge = pq.top(); pq.pop();

        //if you're at the end goal, then you're done.
        if(curEdge.city == end)
        {
            return curEdge.cost;
        }
        //if I don't have enough fuel level to go to the next city, then ignore it.
        if(distance[curEdge.city][curEdge.fuelLevel] < curEdge.cost)
        {
            continue;
        }
        //top off if you can at the current city
        if( curEdge.fuelLevel < fuelCap &&                                                              //if the current fuel level is less than the capacity
            curEdge.cost + fuelCost[curEdge.city] < distance[curEdge.city][curEdge.fuelLevel + 1])      //if the cost of buying fuel is less than buying it someplace else
        {
            distance[curEdge.city][curEdge.fuelLevel + 1] = curEdge.cost + fuelCost[curEdge.city];
            pq.push(edges(curEdge.city, curEdge.fuelLevel + 1, curEdge.cost + fuelCost[curEdge.city]));
        }

        //go to the next city if I have enough gas
        vector <edges> v = graph[curEdge.city];     //current city neighbours
        for(int i = 0; i < v.size(); i++)
        {
            int neighbourDist = v[i].cost;          //cost to go to neighbour city
            int neighbourCityID = v[i].city;        //city ID
            //if you have enough fuel to go to the next city
            if(curEdge.fuelLevel >= neighbourDist)
            {
                int curGas = curEdge.fuelLevel - neighbourDist;
                //if there is a smaller cost to going to the city than before
                if(curEdge.cost < distance[neighbourCityID][curGas])
                {
                    distance[neighbourCityID][curGas] = curEdge.cost;
                    pq.push(edges(neighbourCityID, curGas, curEdge.cost));
                }
            }
        }
    }
    return INT_MAX;
}
