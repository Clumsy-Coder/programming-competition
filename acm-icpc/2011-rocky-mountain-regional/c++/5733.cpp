//DONE
/*
	Ad-hoc problem
	Use two arrays. One for keeping track of the previous iteration and the
	other to calculate the next iteration.
	Check if either all the values in the first array are the same OR too many
	iterations have occured. Otherwise perform the iterated difference. 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int cases = 1;
	while(cin >> n && n)
	{
		int values[20];
		for(int i = 0; i < n; i++)
			cin >> values[i];

		int newArray [n];
		copy(values, values + n, newArray);
		for(int i = 0; ; i++)
		{
			//if all the values in the array the same
			if(count(values, values + n, values[0]) == n)
			{
				cout << "Case " << cases++ << ": " << i << " iterations" << endl;
				break;
			}
			//if number of iterations are too many
			else if(i == 999)
			{
				cout << "Case " << cases++ << ": not attained" << endl;
				break;
			}
			//perform the iteration difference
			else
			{
				for(int k = 0; k < n; k++)
				{
					newArray[k % n] = abs(values[k % n] - values[(k + 1) % n]);
				}

				copy(newArray, newArray + n, values);
			}
		}
	}
}
