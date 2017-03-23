//IN PROGRESS
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>

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
    for(int i = 0; i < numNames; i++)
    {
        string curName;
        getline(cin, curName);
        stringstream ss(curName);
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

        // cout << curName << endl;
        // cout << first << " " << last << endl;
    }
    // cout << endl;
}

void solve()
{
    // set <string> persons;
    vector<string> usernames;
    for(int i = 0; i < names.size(); i++)
    {
        string uname = "";
        uname += names[i].first[0];
        for(int k = 0; k < names[i].last.size() && uname.size() < maxLen; k++)
        {
            if(isalpha(names[i].last[k]))
                uname += names[i].last[k];

            // cout << "uname: " << uname << endl;
        }
        int counter = 0;
        auto it = find(usernames.begin(), usernames.end(), uname);
        // cout << "before while loop: " << (it != usernames.end() ? "uname found " : "uname not found ") << uname << endl;
        while(it != usernames.end())
        {
            counter++;
            if(uname.size() < maxLen)
            {
                if(counter <= 10)
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
            else
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

            // cout << uname << " " << uname.size() << endl;
            it = find(usernames.begin(), usernames.end(), uname);
        }
        usernames.push_back(uname);
        // cout << "added: " << uname << "\tsize: " << usernames.size() << endl;
    }
    cout << "Case " << cases++ << endl;
    for(auto u : usernames)
        cout << u << endl;
}
