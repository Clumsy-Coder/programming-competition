//IN PROGRESS
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		map <char, double> charPair;
		int pairs;
		cin >> pairs;
		while(pairs--)
		{
			char character;
			cin >> character >> charPair[character];
		}

		long long strLines;
		cin >> strLines;
		cin.ignore();//ignore empty line

		long answer = 0;
		for(long long i = 0; i < strLines; i++)
		{
			string curLine;
			getline(cin, curLine);

			long long size = curLine.size();
			for(long long j = 0; j < size; j++)
			{
				if(curLine[j] == ' ' || curLine[j] == '\n')continue;

				answer += charPair[curLine[j]];
			}
		}
		cout << answer / 100 << ".";
		cout << std::setfill('0') << std::setw(2) << (answer % 100) << "$" << endl;
	}
	cout << endl;
}
