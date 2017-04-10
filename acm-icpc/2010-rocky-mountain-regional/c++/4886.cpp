// DONE
/*
	Problem type: string processing, Ad-hoc, data structure
	Data structure: bitset, vector
	Algorithm: linear pass
	Summary: - tokenize by page ranges and store them in a vector of strings.
			 - iterate through each page ranges, extract the ranges and store
			   them in a vector if long long.
			 - print the page if it's within total pages.
			 - print the pages printed.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;

bitset<1001> pages;
string printOrder;
long long totalPages;
vector<string> pOrder;

void tokenizePrintOrder();
void tokenizeRange();
void printPage(const vector<long long> &ranges);

int main()
{
	string temp;
	while(getline(cin, temp) && temp != "0")
	{
		pOrder.clear();
		pages.reset();
		totalPages = stol(temp);
		getline(cin, printOrder);
		tokenizePrintOrder();
		tokenizeRange();
		cout << pages.count() << endl;
	}
}

// seperate by page orders
void tokenizePrintOrder()
{
	stringstream ss(printOrder);
	string temp;
	while(getline(ss, temp, ','))
	{
		pOrder.push_back(temp);
	}
}

// seperate by page ranges
void tokenizeRange()
{
	for(int i = 0; i < pOrder.size(); i++)
	{
		stringstream ss(pOrder[i]);
		string temp;
		vector<long long> ranges;
		while(getline(ss, temp, '-'))
		{
			ranges.push_back(stol(temp));
		}
		printPage(ranges);
	}
}

void printPage(const vector<long long> &ranges)
{
	if(ranges.size() == 1)
	{
		if(ranges[0] <= totalPages)
		{
			pages[ranges[0] - 1] = true;
		}
	}
	else
	{
		// also deals with if the first number is higher than the second number
		// ex: print range 8-4. the for loop will ignore them.
		for(int i = ranges[0]; i <= ranges[1]; i++)
		{
			if(i <= totalPages)
			{
				pages[i - 1] = true;
			}
		}
	}
}
