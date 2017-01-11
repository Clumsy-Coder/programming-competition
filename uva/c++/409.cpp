//INPROGRESS
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k, e;

	while(cin >> k >> e)
	{
		vector<string> keywords;
		for(int i = 0; i < k; i++)
		{
			string curKeyword;
			cin >> curKeyword;
			keywords.push_back(curKeyword);
		}

		vector<string> excuses;
		for(int i = 0; i < e + 1; i++)
		{
			string curExcuse;
			getline(cin, curExcuse);
			excuses.push_back(curExcuse);
		}

		// excuses.pop_back();

		for (int i = 0; i < keywords.size(); ++i)
		{
			cout << keywords[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < excuses.size(); ++i)
		{
			cout << excuses[i] << endl;
		}

		cout << "-------------------" << endl;
	}
}