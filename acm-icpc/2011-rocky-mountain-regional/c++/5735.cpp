#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

void readInput();
void solve();

vector<pair<int, int>> stocks;
unsigned long long n, k1, k2, cases = 1;

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
	for(unsigned long long i = 0; i < n; i++)
	{
		long long price; cin >> price;
		pair<int, int> stockPrice(price, i + 1);	//stock price, date (in this case a counter)
		stocks.push_back(stockPrice);
	}
}

void solve()
{
	//sort by price. ascending
	std::sort(stocks.begin(), stocks.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
		return left.first < right.first;
	});

	vector<pair<int, int>> k1V;
	for(int i = 0; i < k1; i++)
	{
		// cout << stocks[i].second << " ";
		k1V.push_back(stocks[i]);
	}
	// cout << endl;

	//sort by price. deascending
	vector<pair<int, int>> k2V;
	std::sort(stocks.begin(), stocks.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
		return left.first > right.first;
	});

	for(int i = 0; i < k2; i++)
	{
		// cout << stocks[i].second << " ";
		k2V.push_back(stocks[i]);
	}

	//sort by time. ascending
	std::sort(k1V.begin(), k1V.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
		return left.second < right.second;
	});

	// for(auto i : k1V)
	for(int i = 0; i < k1V.size(); i++)
		cout << k1V[i].second << (i == k1V.size() - 1 ? "" : " ");
	cout << endl;

	//sort by time. deascending
	std::sort(k2V.begin(), k2V.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
		return left.second > right.second;
	});

	for(int i = 0; i < k2V.size(); i++)
		cout << k2V[i].second << (i == k2V.size() - 1 ? "" : " ");
	cout << endl;
}
