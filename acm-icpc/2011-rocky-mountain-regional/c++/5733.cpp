#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;

void print(int *values)
{
	for(int cur = 0; cur < n; cur++)
				cout << values[cur] << " ";
			cout << endl;
}

int main()
{
	while(cin >> n && n)
	{
		int values[20];
		for(int i = 0; i < n; i++)
			cin >> values[i];

		print(values);
		
		bool done = false;
		int cases = 1;
		int newArray [n];
		for(int i = 0; ; i++)
		{
			for(int k = 0; k <= n; k++)
			{
				if(i == 0)	//if it's the first iteration
				{
					newArray[k] = abs(values[k] - values[(k + 1) % n]);	
				}
				else
				{
					newArray[k % n] = abs(newArray[k % n] - newArray[(k + 1) % n]);
				}
			}

			print(newArray);


			if(count(values, values + n, values[0]) == n)
			{
				cout << "Case " << cases++ << ": " << i << " iterations" << endl;
				done = true;
				break;
			}

			if(i == 999)
			{
				cout << "Case " << cases++ << ": not attained" << endl;
				done = true;
				break;
			}
		}

	}	

	return 0;
}