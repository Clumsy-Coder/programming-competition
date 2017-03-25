#include <iostream>
#include <vector>
#include <algorithm>
// #include <utility>
#include <queue>
// #include <functional>

using namespace std;

//compare operator for the priority queue
struct ascending
{
	bool operator ()(const std::pair<int,int> &left, const std::pair<int,int> &right)
	{
		return left.first < right.first;
	}
};

struct descending
{
	bool operator ()(const std::pair<int,int> &left, const std::pair<int,int> &right)
	{
		return left.first > right.first;
	}
};

void readInput();
void solve();

// vector<pair<int, int>> stocks;
priority_queue< pair<int, int>, vector< pair<int, int> >, ascending > k1PQ;
priority_queue< pair<int, int>, vector< pair<int, int> >, descending > k2PQ;
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
	// stocks.clear();
	k1PQ = priority_queue<pair<int, int>, vector< pair<int, int> >, ascending>();
	k2PQ = priority_queue<pair<int, int>, vector< pair<int, int> >, descending>();
	// cout << "k1PQ.size(): " << k1PQ.size() << "\tk2PQ.size(): " << k2PQ.size() << endl;
	for(unsigned long long i = 0; i < n; i++)
	{
		long long price; cin >> price;
		pair<int, int> stockPrice(price, i + 1);	//stock price, date (in this case a counter)
		// stocks.push_back(stockPrice);
		//add the pair into k1PQ and k2PQ
		k1PQ.push(stockPrice);
		k2PQ.push(stockPrice);
		if(k1PQ.size() > k1) {k1PQ.pop();}
		if(k2PQ.size() > k2) {k2PQ.pop();}
	}
}

void solve()
{
	//add the elements of k1PQ to a vector 'k1V' up to k1 elements
	//add the elements of k2PQ to a vector 'k2V' up to k2 elements
	//sort k1V by the time in ascending order. The second value in the pair
	//sort k2V by the time in descending order. The second value in the pair
	//print k1V and k2V elements. Display the second value in the pair
	vector<pair<int, int>> k1V, k2V;

	for(int i = 0; i < k1; i++)
	{
		k1V.push_back(k1PQ.top());
		k1PQ.pop();
	}

	for(int i = 0; i < k2; i++)
	{
		k2V.push_back(k2PQ.top());
		k2PQ.pop();
	}

	//sort k1 vector
	sort(k1V.begin(), k1V.end(), [](pair<int,int> &left, pair<int,int> &right) {
		return left.second < right.second;
	});
	//sort k2 vector
	sort(k2V.begin(), k2V.end(), [](pair<int,int> &left, pair<int,int> &right) {
		return left.second > right.second;
	});

	for(int i = 0; i < k1V.size(); i++)
	{
		cout << k1V[i].second << (i == k1V.size() - 1 ? "" : " ");
	}
	cout << endl;

	for(int i = 0; i < k2V.size(); i++)
	{
		cout << k2V[i].second << (i == k2V.size() - 1 ? "" : " ");
	}
	cout << endl;


	// //sort by price. ascending
	// std::sort(stocks.begin(), stocks.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
	// 	return left.first < right.first;
	// });
	//
	// vector<pair<int, int>> k1V;
	// for(int i = 0; i < k1; i++)
	// {
	// 	// cout << stocks[i].second << " ";
	// 	k1V.push_back(stocks[i]);
	// }
	// // cout << endl;
	//
	// //sort by price. descending
	// vector<pair<int, int>> k2V;
	// std::sort(stocks.begin(), stocks.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
	// 	return left.first > right.first;
	// });
	//
	// for(int i = 0; i < k2; i++)
	// {
	// 	// cout << stocks[i].second << " ";
	// 	k2V.push_back(stocks[i]);
	// }
	//
	// //sort by time. ascending
	// std::sort(k1V.begin(), k1V.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
	// 	return left.second < right.second;
	// });
	//
	// // for(auto i : k1V)
	// for(int i = 0; i < k1V.size(); i++)
	// 	cout << k1V[i].second << (i == k1V.size() - 1 ? "" : " ");
	// cout << endl;

	// //sort by time. descending
	// std::sort(k2V.begin(), k2V.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
	// 	return left.second > right.second;
	// });
	//
	// for(int i = 0; i < k2V.size(); i++)
	// 	cout << k2V[i].second << (i == k2V.size() - 1 ? "" : " ");
	// cout << endl;
}
