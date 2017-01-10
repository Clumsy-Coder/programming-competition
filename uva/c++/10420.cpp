#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	map<string, int> countryMap;
	while(cases--)
	{
		string country;
		cin >> country;
		string ignore;
		getline(cin, ignore);
		if(countryMap[country])
		{ 
			countryMap[country]++;
		}
		else
		{
			countryMap[country]++;
		}
	}

	typedef map<string, int>::iterator it;
	for(it iterator = countryMap.begin(); iterator != countryMap.end(); iterator++)
	{
		cout << iterator->first << " " << iterator->second <<endl;
	}
}