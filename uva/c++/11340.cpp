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

struct charType
{
	char character;
	double value;

};

long long dollar = 0;
int cent = 0;

vector<charType> charList;
vector<string> artical;

void printCharList();
void printArticleList();


int findChar(char charValue)
{
	// cout << charValue << endl;
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
		string tempString = artical[i];
		//cout << tempString << endl;
		
		for (unsigned int k = 0; k < tempString.size(); k++)
		{
			int tempValue = findChar(tempString[k]);
			//cout << tempValue << " ";
			if(tempValue > 0)
			{
				if(cent + tempValue >= 100)
				{
					//cout << "." << endl;
					dollar++;
					cent = (cent + tempValue) % 100;
				}

				else
				{
					cent += tempValue;
				}


			}
			
		}
		
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

		//printCharList();

		int articalNum = 0;
		cin >> articalNum;

		// cout <<endl << "artical NUM: " << articalNum << endl;
		string tempString;
		for(int k = 0; k <= articalNum; k++)
		{
			// cout << "k: " << k << endl;
			
			getline(cin, tempString);
			// cout << "tempString: " << tempString << endl;
			artical.push_back(tempString);

		}

		//for some reason the first element is empty, remove it.
		artical.erase(artical.begin());
		//printArticleList();

		
		calculate();
		cout << dollar << ".";
		// cent = 10;
		if(cent < 10)
		{
			cout << std::setfill('0') << std::setw(2) << cent << "$" << endl;
		}

		else
		{
			cout << cent << "$" << endl;
		}
		

	}	

	return 0;
}

void printCharList()
{
	cout << "CharList vector size: " << charList.size() << endl;
	for (unsigned int i = 0; i < charList.size(); ++i)
	{
		cout << "[" << i << "]: " << charList[i].character << " " << charList[i].value << endl;
	}

}

void printArticleList()
{
	cout << "Article vector size: " << artical.size() << endl;
	for (unsigned int i = 0; i < artical.size(); i++)
	{
		cout << "[" << i << "]: " << artical[i] << endl;
	}

}