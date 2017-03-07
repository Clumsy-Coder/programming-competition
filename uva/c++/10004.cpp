//DONE
/*
    Use DFS traversal approach. Same idea as bipartite
    
    Add the node (parent node) into stack and set the colour.
    while there's elements in the stack
        get the node (parent node) in the stack and pop it.
        for each of the parents's node neighbours,
            check if the colour is NOT set.
                set the colour (alternate from the parent) and to the stack
            check if the colour is the same as the parent.
                then it's not bicolourable
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int NOT_SET = -1;
const int BLACK = 0;
const int RED = 1;

//used for constructing the adjacency list
struct node
{
    int nodeNum;
    int colour = NOT_SET;     //-1 = not set, 0 = black colour, 1 = red colour
    vector<int> neighbour;
};

void readInput(vector<node> &adjList);
void solve(vector<node> &adjList);

int main()
{
    int numNodes;
    while(cin >> numNodes && numNodes)
    {
        vector <node> adjacencyList(numNodes);
        readInput(adjacencyList);
        solve(adjacencyList);
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

void solve(vector<node> &adjList)
{
    stack <node> dfs;
    adjList[0].colour = BLACK;
    dfs.push(adjList[0]);
    bool bicolourable = true;
    while(!dfs.empty() && bicolourable)
    {
        node parentNode = dfs.top();
        dfs.pop();
        //go through all it's neighbours and check
        for(int i = 0; i < parentNode.neighbour.size(); i++)
        {
            node *curNode = &adjList[parentNode.neighbour[i]];
            if(curNode->colour == NOT_SET)
            {
                curNode->colour = (parentNode.colour == BLACK) ? RED : BLACK;
                dfs.push(*curNode);
            }
            else if(curNode->colour == parentNode.colour)
            {
                bicolourable = false;
                break;
            }
        }
    }

    (bicolourable) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
}
