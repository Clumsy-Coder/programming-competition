//DONE
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
	int answer1 = numeric_limits<int>::max();
	int answer2 = 0;

	for(int i = 0; i < numBooks; i++)
	{
		first = books[i];
		for(int k = i + 1; k < numBooks; k++)
		{
			second = books[k];
			int temp = first + second;

			if(temp == budget)
			{
				if(abs(first - second) < abs(answer1 - answer2))
				{
					answer1 = first;
					answer2 = second;
				}
			}

		}
	}

	//to make sure the first number is smaller than the second.
	if(answer1 > answer2)
	{
		int temp = answer2;
		answer2 = answer1;
		answer1 = temp;
	}
	cout << "Peter should buy books whose prices are " << answer1 << " and " << answer2 << "." << endl << endl;
	
}