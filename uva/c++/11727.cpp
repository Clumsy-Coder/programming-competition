//DONE!!
#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

int main()
{
	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; i++)
	{
		int salary1;
		int salary2;
		int salary3;

		cin >> salary1 >> salary2 >> salary3;
		vector <int> salList;
		salList.push_back(salary1);
		salList.push_back(salary2);
		salList.push_back(salary3);

		sort(salList.begin(), salList.end());

		cout << "Case " << i + 1 << ": " << salList[1] << endl;


	}

	return 0;

}
