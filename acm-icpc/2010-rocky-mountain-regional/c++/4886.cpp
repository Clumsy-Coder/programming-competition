#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

// vector<bool> pages;
bitset<1001> pages;
string line;
long long totalPages;

void readInput();
void solve();
void parsePageRanges(const vector<string> &pageRanges);
void markPages(const vector<long long> &ranges);
void print();

int main()
{
	string numPages;
	while(getline(cin, numPages) && numPages != "0")
	{
		totalPages = stol(numPages);
		getline(cin, line);
		solve();
	}
}

void solve()
{
	pages.reset();
	string pageRanges;
	vector<string> ranges;
	stringstream ss(line);
	while(getline(ss, pageRanges, ','))
	{
		ranges.push_back(pageRanges);
	}
	parsePageRanges(ranges);
	cout << pages.count() << endl;
}

void parsePageRanges(const vector<string> &pageRanges)
{
	for(unsigned long long i = 0; i < pageRanges.size(); i++)
	{
		vector<long long> range;
		stringstream ss(pageRanges[i]);
		string pages;
		while(getline(ss, pages, '-'))
		{
			range.push_back(stol(pages));
		}
		// sort(range.begin(), range.end());
		markPages(range);
	}
}

void markPages(const vector<long long> &ranges)
{
	if(ranges.size() == 1)
	{
		pages[ranges[0] - 1] = 1;
	}
	else
	{
		if(is_sorted(ranges.begin(), ranges.end()))
		{
			for(int i = ranges[0] - 1; i < ranges[1] && i < totalPages; i++)
			{
				pages[i] = 1;
			}
		}
	}
}

void print()
{
	cout << endl;
	for(int i = 0; i <= totalPages; i++)
	{
		if(pages[i] == 1)
		{
			cout << i + 1 << "\t" << pages[i] << endl;
		}
	}

	cout << endl;
}