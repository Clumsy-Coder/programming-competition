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
		long long count = 0;
		long long eraseIndex = 0;
		long long prevKill = 0;
		vector<char> copy = k;

		// cout << "value: " << value
		// 	 << " g: " << check(copy, 'g')
		// 	 << " b: " << check(copy, 'b') << endl;

		while(true)
		{
			// for(char cur : copy){cout << cur << " ";}
			// cout << "****" << endl;
			eraseIndex = (count + prevKill) % copy.size();
			prevKill = eraseIndex;
			// cout << " ---eraseIndex: " << eraseIndex;
			// cout << " ---count: " << count << endl;

			copy.erase(copy.begin() + eraseIndex);
			if(check(copy, 'g') != value)
			{
				count++;
				copy = k;
				prevKill = 0;
				continue;
			}
			// cout << count << endl;
			// cout << "value: " << value
			// 	 << " g: " << check(copy, 'g')
			// 	 << " b: " << check(copy, 'b') << endl;
			if(check(copy, 'g') == value &&
			   check(copy, 'b') == 0)
			{
				break;
			}
		}

		cout << count + 1 << endl;
		// cout << "/////" << endl;
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
