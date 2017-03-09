//DONE
/*
    Use kruskal minimum spanning tree algorithm
    - create the minimum spanning tree by generating all the possible edges
      for all cities (every city connecting to every OTHER city)
    - sort all the edges from smallest hypotenuse distance to the largest
    - choose the best possible edge and connect them using 'union find'
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind


class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use

      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }

   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//

void solve();
int cases, curCase = 1;
int numCities, numStates, threshold;
double roadLen, railLen;
int city [1001][2];         //stores city coordinaties.

//used for defining an edge between two cities
struct edge
{
    int city1, city2;       //index based
    //calc the distance using hypotenuse.
    //Not to square root because of accuracy issues and costs more CPU resource to square root for every edge
    double dist() const
    {
        //raise to the power of 2
        return pow(city[city1][0] - city[city2][0], 2) +    //x
               pow(city[city1][1] - city[city2][1], 2);     //y
    }

    //for sorting the edges from smallest distance to largest distance
    bool operator < (const edge &edge2) const
    {
        return dist() < edge2.dist();
    }
};

int main()
{
    cin >> cases;
    while(cases--)
    {
        numCities = roadLen = railLen = 0; numStates = -1;  //reset the values
        cin >> numCities >> threshold;

        //read the city coordinates
        for(int i = 0; i < numCities; i++)
        {
            cin >> city[i][0] >> city[i][1];
        }

        solve();
        cout << "Case #" << curCase++ << ": "
             << ((numStates < 0) ? 1 : numStates) << " "
             << round(roadLen) << " "
             << round(railLen) << endl;
    }
}

//use kruskal minimum spanning tree algorithm
void solve()
{
    int connectedCities = numCities;
    //generate all the edges. assuming every city connects to every other city
    vector<edge> allEdges(numCities * (numCities - 1));
    for(int i = 0, curEdge = 0; i < numCities; i++)
    {
        for(int j = i + 1; j < numCities; j++, curEdge++)
        {
            allEdges[curEdge].city1 = i;
            allEdges[curEdge].city2 = j;
        }
    }

    //sort the edges to get smallest distance first
    sort(allEdges.begin(), allEdges.end());
    UnionFind cities(numCities);

    //go through all edges and connect best possible ones.
    for(int i = 0; i < allEdges.size(); i++)
    {
        //if the current edge distance is greater than the threshold,
        //then more states are needed
        if((allEdges[i].dist() > pow(threshold, 2)) && numStates < 0)
        {
            numStates = connectedCities;
        }

        int city1 = cities.find(allEdges[i].city1);
        int city2 = cities.find(allEdges[i].city2);

        //ignore if the two cities are already connected
        //also prevents cycles in minimum spanning tree
        if(city1 == city2) {continue;}

        //connect the two cities
        cities.merge(city1, city2);
        connectedCities--;

        if(numStates < 0)
        {
            roadLen += sqrt(allEdges[i].dist());
        }
        else
        {
            railLen += sqrt(allEdges[i].dist());
        }
    }
}
