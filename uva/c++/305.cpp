//DONE

/*
	get input 'm'
	check if the answer is computed for the input 'm'
		print the answer from map
	else
		call solve function
			create a vector of char
			add 'm' # of 'g' in the vector
			add 'm' # of 'b' in the vector
			create a copy vector of the original
			while true //note: only break the loop when the answer is computed
				compute the index to erase and set it to 'eraseIndex': (count + prevKill) % vector.size()
					//note: prevKill and count is initially 0. stored in index form
				set prevKill to eraseIndex
				erase element at index eraseIndex
				check if # of 'g' is NOT the same as 'm'	//check(vector<char>, char) returns the number of 'char' in the vector
					count++
					set the copy vector to the original
					prevKill = 0
					continue
				end if

				check if # of 'g' is 'm' AND # of 'b' is 0
					//answer found. note: the answer is in index, so it's needs +1
					add the answer to the map. mk[m] = count + 1
					display the answer
					break out of the loop
				end if
			end while
		end solve function
	end else
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int check(const vector<char> &v, char value);
void solve(int m, map<int, long long> &mk);

map<int, long long> mk;

int main()
{
	int value;
	while(cin >> value && value)
	{
		if(mk.count(value) == 1)
		{
			cout << mk[value] << endl;
		}
		else
		{
			solve(value, mk);
		}
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

void solve(int m, map<int, long long> &mk)
{
	vector<char> k;
	for(int i = 0; i < m; i++)
	{
		k.push_back('g');
	}
	for(int i = 0; i < m; i++)
	{
		k.push_back('b');
	}
	long long count = 0;
	long long eraseIndex = 0;
	long long prevKill = 0;
	vector<char> copy = k;

	while(true)
	{
		eraseIndex = (count + prevKill) % copy.size();
		prevKill = eraseIndex;

		copy.erase(copy.begin() + eraseIndex);
		if(check(copy, 'g') != m)
		{
			count++;
			copy = k;
			prevKill = 0;
			continue;
		}

		if(check(copy, 'g') == m &&
		   check(copy, 'b') == 0)
		{
			mk[m] = count + 1;
			break;
		}
	}
	cout << count + 1 << endl;
}
