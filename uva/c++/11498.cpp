//DONE!!
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
	int numCases;
	cin >> numCases;

	while(numCases != 0)
	{
		int divisionX;
		int divisionY;

		cin >> divisionX >> divisionY; 

		for (int i = 0; i < numCases; i++)
		{
			int resX;
			int resY;

			cin >> resX >> resY;

			//if one of the res coordinates is the same as division coordinates
			if(resX == divisionX || resY == divisionY)
			{
				cout << "divisa" << endl;

			}

			//if res is in the NW
			else if(resX < divisionX && resY > divisionY)
			{
				cout << "NO" << endl;

			}

			//if res is in the NE
			else if(resX > divisionX && resY > divisionY)
			{
				cout << "NE" << endl;

			}

			//if res is in the SW
			else if(resX < divisionX && resY < divisionY)
			{
				cout << "SO" << endl;

			}

			//if res in the SE
			else if(resX > divisionX && resY < divisionY)
			{
				cout << "SE" << endl;

			}


		}

		cin >> numCases;

	}

	return 0;

}
