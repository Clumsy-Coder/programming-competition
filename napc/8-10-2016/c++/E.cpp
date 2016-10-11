//DONE!!

/*
	Solution approach
	
	get the input for number of names to be entered
	for loop the number and get the name
	add to a list

	loop through the nameList. leave the last element in the list, for avoiding index out of bound exception.
	if element at i and i+1 is increasing, then set the bool increasing to true
	if element at i and i+1 is decreasing, then set the bool decreasing to true

	if increasing bool is true and decreasing bool is false, then the list is increasing
	if decreasing bool is true and increasing bool is false, then the list is decreasing
	else it's neither increasing or decreasing.

*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> nameList;

int main(){
	int numList = 0;

	cin >> numList;

	for (int i = 0; i < numList; i++)
	{
		string name = "";
		cin >> name;
		nameList.push_back(name);
	}

	//compare the list is increasing, decreasing, or neither.
	bool increasing = false;
	bool decreasing = false;
	//bool neither 	= false;

	for (int unsigned i = 0; i < nameList.size(); i++)
	{
		if (i != nameList.size() - 1)
		{
			//compare element i and i + 1
			if(nameList[i].compare(nameList[i + 1]) < 0)
			{
				//cout << "increasing ";
				increasing = true;
			}
			else if (nameList[i].compare(nameList[i + 1]) > 0)
			{
				//cout << "decreasing ";
				decreasing = true;
			}
		}

	}

	//cout << endl;

	//if the increasing bool is true and decreasing is false, then the list is increasing
	if (increasing == true && decreasing == false)
	{
		cout << "INCREASING" << endl;
	}
	//if the decreasing bool is true and increasing is false, then the list is decreasing
	else if (decreasing = true && increasing == false)
	{
		cout << "DECREASING" << endl;
	}
	//if both increasing and decreasing are true, then the list is not increasing or decreasing.
	//else if(increasing == true && decreasing == true)
	else
	{
		cout << "NEITHER" << endl;
	}

	return 0;
}