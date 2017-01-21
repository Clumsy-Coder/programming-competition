//DONE
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

string removeNonAlpha(string name)
{
	string newStr = "";
	for (unsigned int i = 0; i < name.size(); ++i)
	{
		if(isalpha(name[i]) && !isspace(name[i]))
		{
			newStr += name[i];
		}
	}
	return newStr;
}

int main()
{
    string name1, name2;
    while(getline(cin, name1))
    {
        getline(cin, name2);
        //lower case the names
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
        name1 = removeNonAlpha(name1);
        name2 = removeNonAlpha(name2);

        if(name1.size() == 0 && name2.size() == 0)
        {
            cout << endl;
            continue;
        }

        int name1Ans = 0;
        int name2Ans = 0;
        for(int i = 0; i < name1.size(); i++)
        {
            if(name1[i]>='a'&& name1[i]<='z')
            {
                name1Ans += name1[i] - 96;
            }
        }

        for(int i = 0; i < name2.size(); i++)
        {
            if(name2[i]>='a'&& name2[i]<='z')
            {
                name2Ans += name2[i] - 96;
            }
        }

        while(name1Ans > 9)
        {
            name1Ans = (name1Ans / 10) + (name1Ans % 10);
        }
        while(name2Ans > 9)
        {
            name2Ans = (name2Ans / 10) + (name2Ans % 10);
        }

        if(name1Ans < name2Ans)
        {
            cout << fixed << setprecision(2) << (double)(name1Ans / (double)name2Ans)*100 << " %" << endl;
        }
        else
        {
            cout << fixed << setprecision(2) << (double)(name2Ans / (double)name1Ans)*100 << " %" << endl;
        }
    }
}
