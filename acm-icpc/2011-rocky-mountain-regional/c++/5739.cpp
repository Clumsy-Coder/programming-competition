//IN PROGRESS
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct person
{
    string first, last;
    person(string firstname, string lastname)
    {
        first = firstname;
        last = lastname;
    }
};

void readInput();
void solve();

int numNames, maxLen;
int cases = 1;
vector<person> names;
int main()
{
    while(cin >> numNames >> maxLen && (numNames && maxLen))
    {
        names.clear();
        cin.ignore();
        readInput();
        solve();
    }
}

void readInput()
{
    for(int curName = 0; curName < numNames; curName++)
    {
        string name;
        getline(cin, name);
        stringstream ss(name);
        string temp;
        vector <string> tempV;
        while(ss >> temp)
        {
            tempV.push_back(temp);
        }

        string first, last;
        if(tempV.size() == 2)
        {
            first = tempV[0];
            last = tempV[1];
        }
        else
        {
            first = tempV[0];
            last = tempV[tempV.size() - 1];
        }
        transform(first.begin(), first.end(), first.begin(), ::tolower);
        transform(last.begin(), last.end(), last.begin(), ::tolower);
        names.push_back(person(first, last));
    }
}

void solve()
{
    vector<string> usernames;
    for(int i = 0; i < names.size(); i++)
    {
        string uname = "";
        uname += names[i].first[0];
        for(int k = 0; k < names[i].last.size() && uname.size() < maxLen; k++)
        {
            if(isalpha(names[i].last[k]))
                uname += names[i].last[k];
        }
        int counter = 1;
        for(auto it = find(usernames.begin(), usernames.end(), uname);
            it != usernames.end();
            it = find(usernames.begin(), usernames.end(), uname), counter++)
        {
            //if the size of username is less than maxLen
            if(uname.size() < maxLen)
            {
                //check the difference between the uname and the maxLen
                int diff = abs((int)uname.size() - maxLen);
                if(diff == 1 && counter < 10)
                {
                    uname += to_string(counter);
                }
                else
                {
                    for(int k = 0; k < diff + 1; k++)
                    {
                        uname.pop_back();
                    }
                    uname += to_string(counter);
                }

            }
            //if the size of username is equal to maxLen
            else if(uname.size() == maxLen)
            {
                if(counter < 10)
                {
                    uname.pop_back();
                    uname += to_string(counter);
                }
                else
                {
                    uname.pop_back();
                    uname.pop_back();
                    uname += to_string(counter);
                }
            }
            //if the size of username is greater than maxLen
            else if(uname.size() > maxLen)
            {
                int diff = abs((int)uname.size() - maxLen);
                for(int k = 0; k < diff; k++)
                {
                    uname.pop_back();
                }

                if(counter < 10)
                {
                    uname.pop_back();
                    uname += to_string(counter);
                }
                else
                {
                    uname.pop_back();
                    uname.pop_back();
                    uname += to_string(counter);
                }
            }
        }
        usernames.push_back(uname);
    }
    cout << "Case " << cases++ << endl;
    for(auto u : usernames)
        cout << u << endl;
}
