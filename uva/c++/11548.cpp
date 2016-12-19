//DONE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int words = 0;
int cases = 0;
string wordList [72];

int solve(string firstWord, string secondWord);

int main()
{
	cin >> cases;
	
	for(int i = 0; i < cases; i++)
	{

		cin >> words;
		for(int j = 0; j < words; j++)
		{
			cin >> wordList[j];

		}

		int maxAnswer = 0;
		for(int j = 0; j < words; j++)
		{
			for(int k = 0; k < words; k++)
			{
				if (j != k)
					maxAnswer = max(solve(wordList[j], wordList[k]), maxAnswer);
			}
		}

		cout << maxAnswer << endl;

	}

	return 0;
}

int solve(string firstWord, string secondWord)
{
	long long answer = 0;
	string temp = secondWord;
	
	for(int i = 0; i < firstWord.size(); i++)
	{
		long long count = 0;
		// int shift = 0;
		
		for(int j = 0; j < temp.size(); j++)
		{
			if(j < firstWord.size() && firstWord[j] == temp[j])
			{
				count++;
				
			}

		}

		answer = max(answer, count);
		temp.insert(0, "0");
	
	}

	return answer;

}