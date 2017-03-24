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
void solve(string username);

int numNames, maxLen;
int cases = 1;
map<string, int> uMap;

int main()
{
    while(cin >> numNames >> maxLen && (numNames && maxLen))
    {
        cout << "Case " << cases++ << endl;
        uMap.clear();
        cin.ignore();
        readInput();
    }
}

void readInput()
{
    for(int curName = 0; curName < numNames; curName++)
    {
        string getName; getline(cin, getName);
        stringstream ss(getName);
        string temp; vector <string> tempV;
        while(ss >> temp)
        {
            tempV.push_back(temp);
        }

        string first = tempV[0];
        string last = tempV[tempV.size() - 1];

        transform(first.begin(), first.end(), first.begin(), ::tolower);
        transform(last.begin(), last.end(), last.begin(), ::tolower);

        string username = ""; username += first[0];
        for(int i = 0; i < last.size() && username.size() < maxLen; i++)
            if(isalpha(last[i]))
                username += last[i];

        if(uMap.find(username) == uMap.end())
            uMap[username] = 0;
        else
            uMap[username]++;

        solve(username);
    }
}

void solve(string username)
{
    int counter = uMap[username];
    if(counter != 0)
    {
        //pop of the last character as long the size of the username and
        //counter (1 digit or 2 digits) is greater than maxLen
        while(username.size() + (counter < 10 ? 1 : 2) > maxLen)
        {
            username.pop_back();
        }
        username += to_string(counter);
    }
    cout << username << endl;
}
