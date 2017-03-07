#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int nodeNum;
    int colour = -1;     //-1 = not set, 0 = black colour, 1 = red colour
    vector<int> neighbour;
};

void readInput(vector<node> &adjList);
void solve(vector<node> &adjList);
void print(const vector<node> &adjList);

void print(vector<node> &adjList)
{
    for(int i = 0; i < adjList.size(); i++)
    {
        cout << i << " ";
        for(int neighbourNode = 0; neighbourNode < adjList[i].neighbour.size(); neighbourNode++)
        {
            cout << adjList[i].neighbour[neighbourNode] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numNodes;
    while(cin >> numNodes && numNodes)
    {
        vector <node> adjacencyList(numNodes);
        readInput(adjacencyList);
        print(adjacencyList);
        cout << endl;
    }
}

void readInput(vector<node> &adjList)
{
    int numEdges;
    cin >> numEdges;
    for(int i = 0; i < numEdges; i++)
    {
        int node, neighbourNode;
        cin >> node >> neighbourNode;
        adjList[node].neighbour.push_back(neighbourNode);
        adjList[neighbourNode].neighbour.push_back(node);
    }
}
