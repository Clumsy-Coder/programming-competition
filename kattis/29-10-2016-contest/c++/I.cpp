//DONE
#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(const pair<string, int>&i, const pair<string, int>&j);

int main()
{
    int cups;
    cin >> cups;
    vector <pair<string, int > > list;
    for(int i = 0; i < cups; i++)
    {
        string string1;
        string string2;

        cin >> string1 >> string2;
        int diameter;
        if(atoi(string1.c_str()) != 0)
        {
            diameter = atoi(string1.c_str());
            pair<string, int> cup(string2, diameter);
            list.push_back(cup);


        }

        else if(atoi(string2.c_str()) != 0)
        {
            diameter = atoi(string2.c_str()) * 2;
            pair <string, int> cup(string1, diameter);
            list.push_back(cup);
        }


    }

    sort(list.begin(), list.end(), compare);
    for(int i = 0; i < list.size(); i++)
    {
        cout << list[i].first << endl;
    }

    return 0;
}

bool compare(const pair<string, int>&i, const pair<string, int>&j)
{
    return i.second < j.second;
}
