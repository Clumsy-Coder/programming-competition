//DONE
/*
    String processing problem

    add the first char of the firstname
    append all alphabets  of the lastname up the maxLen,
    check if the username existes in the map.
        if true: then add an entry with value of 0
        else: incrment the value using the username as the key
    print out the username with the apprpiate conditions using
        the counter value in the map
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

void readInput();
void solve(string uname);

int numNames, maxLen;
int cases = 1;
map<string, int> usernameMap;
int main()
{
    while(cin >> numNames >> maxLen && (numNames && maxLen))
    {
        cout << "Case " << cases++ << endl;
        usernameMap.clear();
        cin.ignore();
        readInput();
    }
}

void readInput()
{
    for(int curName = 0; curName < numNames; curName++)
    {
        string getName;
        getline(cin, getName);
        stringstream ss(getName);
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

        string uname = ""; uname += first[0];
        for(int k = 0; k < last.size() && uname.size() < maxLen; k++)
        {
            if(isalpha(last[k]))
                uname += last[k];
        }

        if(usernameMap.find(uname) == usernameMap.end())
        {
            usernameMap[uname] = 0;
        }
        else
        {
            usernameMap[uname]++;
        }

        solve(uname);
    }
}

void solve(string uname)
{
    int counter = usernameMap[uname];
    if(counter != 0)
    {
        if(abs((int)uname.size() + (counter < 10 ? 1 : 2)) < maxLen)
        {
            uname += to_string(counter);
        }
        else
        {
            //pop of the last character as long the size of the username and
            //counter (1 digit or 2 digits) is greater than maxLen
            while(abs((int)uname.size() + (counter < 10 ? 1 : 2)) > maxLen)
            {
                uname.pop_back();
            }
            uname += to_string(counter);
        }
    }
    cout << uname << endl;
}
