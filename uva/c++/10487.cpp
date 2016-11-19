//IN PROGRESS
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void solve(int query);

int cases = 1;
int n = 0;
// vector<int> nList;
// vector<int> mList;
int nList [1002];
int mList [26];
int m = 0;
int main()
{
	
	while(cin >> n && n != 0)
	{
		for(int i = 0; i < n; i++)
		{
			int nValue = 0;
			cin >> nValue;
			// nList.push_back(nValue);
			nList[i] = nValue;
		}

		
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			int mValue = 0;
			cin >> mValue;
			// mList.push_back(mValue);
			mList[i] = mValue;
		}
		
		cout << "Case " << cases++ << ":" << endl;
		for(int i = 0; i < m; i++)
		{
			solve(mList[i]);
		}


	}

	return 0;
}

void solve(int query)
{
	int first;
	int second;
	int smallest = 0; //contains the value in nList.
	for(int i = 0 ; i < n; i++)
	{
		first = nList[i];

		for(int k = i + 1; k < n; k++)
		{
			second = nList[k];
			if(first + second >= smallest &&
			   first + second <= query)
			{
				smallest = first + second;
			}

		}
	}

	cout << "Closest sum to " << query << " is " << smallest << "." << endl;
}