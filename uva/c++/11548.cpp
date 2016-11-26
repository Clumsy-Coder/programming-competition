//IN PROGRESS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int words = 0;
int cases = 0;
string wordList [72];

void solve(string firstWord, string secondWord);

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

		for(int j = 0; j < words; j += 2)
		{
			solve(wordList[j], wordList[j + 1]);
		}

	}

	return 0;
}

void solve(string firstWord, string secondWord)
{
	long long answer = 0;
	
	for(int j = 0; j < firstWord.size() ; j++)
	{
		if(firstWord[j] == secondWord[j])
		{
			answer++;
		}

	}

	cout << answer << endl;

}