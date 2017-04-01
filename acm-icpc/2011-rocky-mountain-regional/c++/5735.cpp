//DONE

/*
	Ad-hoc problem
	summary: store the values in a vector of pairs.
				the first value is the price and the second is the time.
		   	 sort the vector lexicographically
		     get the k1 time values in a vector and sort in ascending order
		     get the k2 time values in a vector and sort in descending order
		     print the values

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void readInput();
void solve();

vector<pair<int, int>> stocks;
int n, k1, k2, cases = 1;

int main()
{
	while(cin >> n >> k1 >> k2 && (n && k1 && k2))
	{
		cout << "Case " << cases++ << endl;
		readInput();
		solve();
	}
}

void readInput()
{
	stocks.clear();
	for(int i = 0; i < n; i++)
	{
		int price; cin >> price;
		stocks.push_back(make_pair(price, i + 1));
	}

	//sort the vector lexicographically
	sort(stocks.begin(), stocks.end());

}

void solve()
{
	vector<int> k1V, k2V;
	//get the k1 values
	for(int i = 0; i < k1; i++)
	{
		k1V.push_back(stocks[i].second);
	}

	//get the k2 values
	for(int i = n - k2; i < n; i++)
	{
		k2V.push_back(stocks[i].second);
	}

	//sort in ascending order
	sort(k1V.begin(), k1V.end());
	//sort in descending order
	sort(k2V.begin(), k2V.end(),  greater<int>());

	for(int i = 0; i < k1V.size(); i++)
		cout << k1V[i] << (i != k1V.size() - 1 ? " " : "");
	cout << endl;

	for(int i = 0; i < k2V.size(); i++)
		cout << k2V[i] << (i != k2V.size() - 1 ? " " : "");
	cout << endl;
}
