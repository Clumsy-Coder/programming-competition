//INPROGRESS

/*
	read keywords
	add the keyword into a set (for making it easier to search)

	read the excuse
	add the excuse into a vector

	iterate through the excuses
		use istringstream to get the word from the excuse
		lower case the word
		call check function
			iterate through the word
				check if it's an alphabet character by character
					concatenate to a tempprary string of the character being checked
			search the excuse word in keywords set
				if found return true
				else return false;

		if check function returns true
			increment a counter
		if current counter is higher than maxCounter
			clear the answer vector
			set maxCounter to counter
			add current excuse sentence to answer vector
		else if current counter is equal to maxCounter
			add current excuse to answer vector

	print the answer
		iterate through the answer vector answer and print it.
*/

#include <iostream>		//cin, cout, getline
#include <sstream>		//istringstream
#include <vector>		//excuses, answer
#include <set>			//keywords
#include <algorithm>	//transform
#include <string>

using namespace std;

bool check(string excuseWord);
string removeNonAlpha(string excuse);

set<string> keywords;
int main()
{
	int k, e;
	int cases = 1;
	while(cin >> k >> e)
	{
		vector<string> answer;
		keywords.clear();
		for(int i = 0; i < k; i++)
		{
			string curKeyword;
			cin >> curKeyword;
			keywords.insert(curKeyword);
		}

		cin.ignore();
		vector<string> excuses;
		for(unsigned int i = 0; i < e; i++)
		{
			string curExcuse;
			getline(cin, curExcuse);
			excuses.push_back(curExcuse);
		}

		int maxOccurrence = -1;
		for (unsigned int i = 0; i < excuses.size(); ++i)
		{
			string curExcuse = removeNonAlpha(excuses[i]);
			istringstream iss(curExcuse);
			string temp;
			int counter = 0;
			while(iss >> temp)
			{
				transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				if(keywords.find(temp) != keywords.end())
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
		for(unsigned int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << endl;
		}

		cout << endl;
	}
}

string removeNonAlpha(string excuse)
{
	string newStr = "";
	for (unsigned int i = 0; i < excuse.size(); ++i)
	{
		if(!isalpha(excuse[i]))
		{
			newStr += " ";
		}
		else
		{
			newStr += excuse[i];
		}
	}

	return newStr;
}