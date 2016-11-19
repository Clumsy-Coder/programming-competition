//DONE
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

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
			cin >> nList[i];
		}

		
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			cin >> mList[i];
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
	int smallest_diff = numeric_limits<int>::max(); //contains the value in nList.
	int best_sum;
	for(int i = 0 ; i < n; i++)
	{
		first = nList[i];

		for(int k = i + 1; k < n; k++)
		{
			second = nList[k];
			int temp = first + second;
			
			//check the absolute difference of the query and the sum of first + second
			//	it must be smaller than the smallest_diff (which contains the smallest value closest to query)
			if(abs(query - temp) <= smallest_diff)
			{
				smallest_diff = abs(query - temp);
				best_sum = first+second;
			}

		}
	}

	cout << "Closest sum to " << query << " is " << best_sum << "." << endl;
}