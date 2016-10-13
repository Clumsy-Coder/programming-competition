//DONE!!
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++)
	{
		int firstOperator;
		int secondOperator;
		cin >> firstOperator >> secondOperator;
		if(firstOperator > secondOperator)
		{
			cout << ">" << endl;

		}

		else if(firstOperator < secondOperator)
		{
			cout << "<" << endl;

		}

		else if (firstOperator == secondOperator)
		{
			cout << "=" << endl;

		}

		else
		{
			cout << "error" << endl;

		}
	}

}
