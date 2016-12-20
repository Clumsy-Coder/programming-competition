//DONE
#include <iostream>

using namespace std;

int main()
{
	int dur;
	double downPay;
	double loan;
	int numDep;
	double deps[101];

	while(cin >> dur >> downPay >> loan >> numDep &&
	      (dur > 0))
	{
		while(numDep--)
		{
			int month;
			double curDep;
			cin >> month >> curDep;
			for(int i = month; i < 101; i++)
			{
				deps[i] = curDep;
			}

		}

		int totalMonths = 0;
		double curLoan = loan;
		double monthlyPay = loan / dur;
		double curPaid = (loan + downPay) * (1 - deps[0]);

		while(curPaid < curLoan)
		{
			totalMonths++;
			curLoan -= monthlyPay;
			curPaid = curPaid * (1 - deps[totalMonths]);

		}

		(totalMonths != 1)?
			cout << totalMonths << " months" << endl:
			cout << totalMonths << " month" << endl;

	}

	return 0;
}
