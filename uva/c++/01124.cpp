//DONE!!
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string input;
	while (getline(cin, input)) 
	{
		if(input.size() > 0)
		{
			cout << input << endl;
		}
		else
		{
			break;
		}

	}
	

}
