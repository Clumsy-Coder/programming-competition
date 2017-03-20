#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k1, k2;
	int cases = 1;
	while(cin >> n >> k1 >> k2 && (n && k1 && k2))
	{
		vector <int> prices;
		
		bool donek1 = false;
		for(int i = 0; i < n; i++)
		{
			int value;
			cin >> value;
			prices.push_back(value);
		}
		
		cout << "Case " << cases++ << endl;
		sort(prices.begin(), prices.end());

		// for(auto val : prices)
		// 	cout << val << " ";

		// cout << endl;

		for(int i = 0; i < k1; i++)
		{
			cout << i + 1 << " ";
		}
		cout << endl;

		for(int i = prices.size(); i > prices.size() - k2; i--)
		{
			cout << i<< " ";
		}
		cout << endl;
	}
}