//DONE
#include <iostream>
#include <sstream>

using namespace std;

//Howard Cheng's code Union
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

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

//End Howard Cheng's code
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void solve(int numComp);

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    for(int i = 0; i < cases; i++)
    {
        if(i > 0){cout << endl;}
        int numComp;
        cin >> numComp;
        // cout << numComp << endl;
        solve(numComp);

    }
}

void solve(int numComp)
{
    UnionFind curUnion(numComp + 1); // +1 for simplicity. UnionFind is 0 based
    string line;
    cin.ignore();
    int connected = 0;
    int notConnected = 0;
    while(getline(cin, line) && line.size() != 0)
    {
        // cout << line << endl;
        stringstream ss(line);
        char curComp;
        int i, j;
        ss >> curComp >> i >> j;

        switch(curComp)
        {
            case 'c':
            {
                curUnion.merge(i, j);
                break;
            }
            case 'q':
            {
                (curUnion.find(i) == curUnion.find(j) ) ? connected++ : notConnected++;
                break;
            }
        }
    }
    cout << connected << "," << notConnected << endl;
}
