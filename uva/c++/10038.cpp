#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
//IN PROGRESS
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;

int main()
{
	string const jolly="Jolly";
	string const not_jolly="Not Jolly";
	string line = "";
	

	while(getline(cin, line) && line.length())
	{
		vector<int> list;
		stringstream ss (line);
		int temp = 0;
		
		while(ss.rdbuf()->in_avail() != 0)
		{	
			ss >> temp;
			list.push_back(temp);
		}



	}

	return 0;
}
