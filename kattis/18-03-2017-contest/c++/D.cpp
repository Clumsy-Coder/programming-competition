//DONE
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{	
		int ans = m - n;
		if(ans > 0)
		{
			if(ans == 1)
			{
				cout << "Dr. Chaz will have 1 piece of chicken left over!\n";
			}
			else
			{
				cout << "Dr. Chaz will have " << ans << " pieces of chicken left over!\n";
			}
			
		}
		else
		{
			if(abs(ans) == 1)
			{
				cout << "Dr. Chaz needs 1 more piece of chicken!\n";
			}

			else
			{
				cout << "Dr. Chaz needs " << abs(ans) << " more pieces of chicken!\n";
			}
		}
	}
}