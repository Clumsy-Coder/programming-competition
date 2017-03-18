//DONE
#include <iostream>

using namespace std;

int main()
{
	long long value;
	while(cin >> value)
	{
		if(value == 0 || value == 1)
		{
			cout << "0\n";
		}

		else
		{
			long long total = 1;
			for(int i = 0; i < value; i++)
				total *= 2;

			cout << total - value - 1 << endl;

		}
		
	}
}