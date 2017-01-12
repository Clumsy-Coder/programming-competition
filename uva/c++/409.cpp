//INPROGRESS
#include <iostream>		//cin, cout, getline
#include <sstream>		//istringstream
// #include <algorithm>
#include <vector>		//excuses, answer
#include <set>			//keywords
// #include <cctype>

using namespace std;

bool check(string excuseWord);

set<string> keywords;
int main()
{
	int k, e;
	int cases = 1;
	while(cin >> k >> e)
	{
		if(cases > 1){cout << endl;} //adding a new line for the next case
		vector<string> answer;
		keywords.clear();
		for(int i = 0; i < k; i++)
		{
			string curKeyword;
			cin >> curKeyword;
			keywords.insert(curKeyword);
		}

		vector<string> excuses;
		for(int i = 0; i < e + 1; i++)
		{
			string curExcuse;
			getline(cin, curExcuse);
			// transform(curExcuse.begin(), curExcuse.end(), curExcuse.begin(), ::tolower);
			excuses.push_back(curExcuse);
		}

		int maxOccurrence = -1;
		for (int i = 0; i < excuses.size(); ++i)
		{
			istringstream iss(excuses[i]);
			string temp;
			int counter = 0;
			while(iss >> temp)
			{
				transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				if(check(temp))
				{
					counter++;
				}

			}

			if(counter > maxOccurrence)
			{
				answer.clear();
				maxOccurrence = counter;
				answer.push_back(excuses[i]);
			}
			else if(counter == maxOccurrence)
			{
				answer.push_back(excuses[i]);
			}

		}

		cout << "Excuse Set #" << cases++ << endl;
		for(int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << endl;
		}
	}
}

bool check(string excuseWord)
{
	string tempstr = "";
	for(int i = 0; i < excuseWord.size(); i++)
	{
		if(isalpha(excuseWord[i]))
		{
			tempstr += excuseWord[i];
		}
	}

	if(keywords.find(tempstr) != keywords.end())
	{
		return true;
	}

	else
	{
		return false;
	}
}
