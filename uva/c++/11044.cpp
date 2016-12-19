//DONE
#include <iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int row;
		int col;
		cin >> row >> col;
		cout << (row/3) * (col/3) << endl;
	}
}
