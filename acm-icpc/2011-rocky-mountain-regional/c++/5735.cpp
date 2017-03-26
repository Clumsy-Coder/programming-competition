#include <iostream>
#include <vector>
#include <algorithm>

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

	sort(stocks.begin(), stocks.end(), [](pair<int,int> &left, pair<int,int> &right) {
		return left.first < right.first;
	});

}

void solve()
{
	vector <pair<int, int> > k1V(stocks.begin(), stocks.begin() + k1);
	vector <pair<int, int> > k2V(stocks.end() - k2, stocks.end());

	sort(k1V.begin(), k1V.end(), [](pair<int,int> &left, pair<int,int> &right) {
		return left.second < right.second;
	});

	sort(k2V.begin(), k2V.end(), [](pair<int,int> &left, pair<int,int> &right) {
		return left.second > right.second;
	});

	for(int i = 0; i < k1V.size(); i++)
		cout << k1V[i].second << (i != k1V.size() - 1 ? " " : "");
	cout << endl;

	for(int i = 0; i < k2V.size(); i++)
		cout << k2V[i].second << (i != k2V.size() - 1 ? " " : "");
	cout << endl;
}
