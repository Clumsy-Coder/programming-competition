//IN PROGRESS
#include <iostream>
#include <vector>

using namespace std;

int check(const vector<char> &v, char value);

int main()
{
	int value;
	while(cin >> value && value)
	{
		vector<char> k;
		for(int i = 0; i < value; i++)
		{
			k.push_back('g');
		}
		for(int i = 0; i < value; i++)
		{
			k.push_back('b');
		}
		long long count = 1;
		vector<char> copy = k;
		while(true)
		{
			long long eraseIndex = count % copy.size();
			copy.erase(copy.begin() + eraseIndex + 1);
			if(check(copy, 'g') < value)
			{
				count++;
				copy = k;
				continue;
			}
			cout << count << endl;
			if(check(copy, 'g') == value && check(copy, 'b') == 0)
			{
				break;
			}
		}

		cout << count << endl;
	}
}

int check(const vector<char> &v, char value)
{
	long long count = 0;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == value)
		{
			count++;
		}
	}

	return count;
}