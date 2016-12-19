//DONE
#include <iostream>

using namespace std;

int main ()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int stops;
		cin >> stops;
		int r = -1000;
		int l = 1000;

		for(int i = 0; i < stops; i++)
		{
			int temp;
			cin >> temp;
			if(temp > r){r = temp;}
			if(temp < l){l = temp;}
		}
		cout << 2 * (r - l) << endl;
	}	

	return 0;

}
