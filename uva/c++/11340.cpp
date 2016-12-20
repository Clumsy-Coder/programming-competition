//IN PROGRESS
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	cin.ignore();
	while(cases--)
	{
		map <int, long> charPair;
		int pairs;
		cin >> pairs;
		while(pairs--)
		{
			char character;
			long value;
			cin >> character >> value;
			charPair[(int)character] = value;
		}

		long long strLines;
		cin >> strLines;
		cin.ignore();

		long long answer = 0;
		for(long long i = 0; i < strLines; i++)
		{
			char curChar;
			while((curChar = cin.get()) != '\n')
			{
				answer += charPair[(int)curChar];
			}
		}
		printf("%.2lf$\n", answer / 100.0);
	}
}
