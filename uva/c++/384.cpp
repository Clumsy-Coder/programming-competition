//DONE
/*
	Make a function for the two rules slump and slimp
	Use recursion to solve the problem
*/

#include <iostream>
#include <string>

using namespace std;

bool isSlump(string str);
bool isSlimp(string str);
bool isSlurpy();

string text;

int main()
{
    int cases; cin >> cases;
    cout << "SLURPYS OUTPUT" << endl;
    while(cases--)
    {
        cout << (isSlurpy() ? "YES" : "NO") << endl;
    }
    cout << "END OF OUTPUT" << endl;
}

bool isSlurpy()
{
    cin >> text;

    for(int i = text.size(); i > 0; i--)
    {
    	if(text[i] == 'H' || text[i] == 'C'){
	    	string str1 = text.substr(0,i+1);
	    	string str2 = text.substr(i+1, text.size()-i);
	        if(isSlimp(str1) && isSlump(str2)){return true;}
	    }
    }

    return false;
}

bool isSlump(string str)
{
	if(str[0] != 'D' && str[0] != 'E') {return false;}
	if(str[1] != 'F') {return false;}
	
	int i = 2;
	while(str[i] == 'F'){i++;}
	
	if(i == str.size() - 1)
	{
		if(str[i] == 'G')
			return true;
	}
	else
	{
		if(isSlump(str.substr(i, str.size() - i)))
		{
			return true;
		}
	}

	return false;
}

bool isSlimp(string str)
{
	if(str[0] != 'A')
	{
		return false;
	}

	if(str.size() == 2)
	{
		if(str[1] == 'H')
		{
			return true;
		}
	}

	else
	{
		if(str[1] == 'B' && isSlimp(str.substr(2, str.size() - 3)) && str[str.size() - 1] == 'C')
		{
			return true;
		}
		else if(isSlump(str.substr(1, str.size() - 2)) && str[str.size() - 1] == 'C')
		{
			return true;
		}
	}
	return false;
}
