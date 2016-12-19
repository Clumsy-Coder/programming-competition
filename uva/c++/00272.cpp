//DONE
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line;
	bool firstQuote = true;
	while(getline(cin, line))
	{
		if(line.empty()){break;}
	
		for(int i = 0; i < line.size(); i++)
		{
			if(line[i] == '\"')
			{
				if(firstQuote == true)
				{
					firstQuote = false;
					cout << "``";
				}
				else
				{
					firstQuote = true;
					cout << "\'\'";
				}
			}
			else
			{
				cout << line[i];
			}
		}
		cout << endl;
	}

	
}
