//IN PROGRESS
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void solve(int budget);

int books [10002];
int numBooks;
int budget;

int main()
{
	while(cin >> numBooks)
	{
		for(int i = 0; i < numBooks; i++)
		{
			cin >> books[i];
		}

		cin >> budget;
		solve(budget);

	}

	return 0;
}

void solve(int budget)
{
	int first;
	int second;
	int smallest_diff = numeric_limits<int>::max();

	int answer1 = 0;
	int answer2 = 0;

	for(int i = 0; i < numBooks; i++)
	{
		first = books[i];
		for(int k = i + 1; i < numBooks; i++)
		{
			second = books[k];
			int temp = first + second;

			if(abs(budget - temp) <= smallest_diff &&
				temp == budget)
			// if(temp == budget)
			{
				smallest_diff = abs(budget - temp);
				answer1 = first;
				answer2 = second;
			}

		}
	}

	cout << "Peter should buy books whose prices are " << answer1 << " and " << answer2 << "." << endl << endl;
	
}