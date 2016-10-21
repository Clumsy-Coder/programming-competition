//IN PROGRESS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int dollar = 0;
int cent = 0;


struct charType
{
	char character;
	double value;

};

vector<charType> charList;
vector<string> artical;

int findChar(char charValue)
{
	int value = 0;

	for (unsigned int i = 0; i < charList.size(); i++)
	{
		if(charList[i].character == charValue)
		{
			value = charList[i].value;
			break;
		}
	}

	return value;
}

void calculate()
{
	for (unsigned int i = 0; i < artical.size(); i++)
	{
		cout << artical[i] << endl;
		/*
		for (unsigned int k = 0; k < artical[i]; k++)
		{

			
			int tempValue = findChar(artical[i][k]);
			if(tempValue > 0)
			{
				if(cent + tempValue > 100)
				{
					dollar++;
					cent = (cent + tempValue) % 100;
				}
			}
			
		}
		*/
	}

}

int main()
{
	int cases = 0;
	cin >> cases;

	for(int i = 0; i < cases; i++)
	{
		int paidChar = 0;
		cin >> paidChar;

		for (int k = 0; k < paidChar; k++)
		{
			char tempChar;
			int tempInt;
			cin >> tempChar >> tempInt;

			charList.push_back(charType());
			charList[charList.size() - 1].character = tempChar;
			charList[charList.size() - 1].value = tempInt;
		}

		
		int articalNum = 0;
		cin >> articalNum;

		cout <<endl << "artical NUM: " << articalNum << endl;
		string tempString;
		for(int k = 0; k <= articalNum; k++)
		{
			cout << "k: " << k << endl;
			
			getline(cin, tempString);
			cout << "tempString: " << tempString << endl;
			artical.push_back(tempString);

		}

		cout << "-----------------------------" << endl;
		cout << "artical.size(): " << artical.size() << endl;
		for (int k = 0; k < artical.size(); k++)
		{
			cout << artical[k] << endl;
		}

		cout << "-----------------------------" << endl;

		/*
		calculate();
		cout << dollar << ".";
		//cent << "$" << endl;
		if(cent < 10)
		{
			cout << std::setfill('0') << std::setw(2) << cent << "$" << endl;
		}
		*/
		

	}	

	return 0;
}