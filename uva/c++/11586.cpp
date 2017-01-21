//DONE
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    while(cases--)
    {
        int total = 0;
        string track;
        getline(cin, track);
        //remove spaces
        string::iterator end_pos = remove( track.begin(),  track.end(), ' ');
        track.erase(end_pos,  track.end());

        if(track.size() == 2)
        {
            cout << "NO LOOP" << endl;
            continue;
        }
        for(int i = 0; i < track.size(); i++)
        {
            (track[i] == 'M') ? total++ : total--;
        }
        (total == 0) ? cout << "LOOP" << endl : cout << "NO LOOP" << endl;
    }
}
