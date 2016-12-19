//DONE
#include <iostream>

using namespace std;

int main()
{
	int cases;
	int curCase = 1;
	while(cin >> cases && cases != 0)
	{
		long sum = 0;
		for(int i = 0; i < cases; i++)
		{
			int temp = 0;
			cin >> temp;
			(temp > 0) ? sum++ : sum--;
		}

		cout << "Case " << curCase++ << ": " << sum << endl;		

	}
}
