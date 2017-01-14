//INPROGRESS
#include <iostream>
#include <map>
#include <array>

using namespace std;

void setup();

int fingers [10]; //10 fingers. each index contains # of times that finger was pressed.
int main()
{
    map<char, std::array<int, 10>> octaves =
    {
        {'c', {{0, 1, 1, 1, 0, 0, 1, 1, 1, 1}}},
        {'d', {{0, 1, 1, 1, 0, 0, 1, 1, 1, 0}}},
        {'e', {{0, 1, 1, 1, 0, 0, 1, 1, 0, 0}}},
        {'f', {{0, 1, 1, 1, 0, 0, 1, 0, 0, 0}}},
        {'g', {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0}}},
        {'a', {{0, 1, 1, 0, 0, 0, 0, 0, 0, 0}}},
        {'b', {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0}}},
        {'C', {{0, 0, 1, 0, 0, 0, 0, 0, 0, 0}}},
        {'D', {{1, 1, 1, 1, 0, 0, 1, 1, 1, 0}}},
        {'E', {{1, 1, 1, 1, 0, 0, 1, 1, 0, 0}}},
        {'F', {{1, 1, 1, 1, 0, 0, 1, 0, 0, 0}}},
        {'G', {{1, 1, 1, 1, 0, 0, 0, 0, 0, 0}}},
        {'A', {{1, 1, 1, 0, 0, 0, 0, 0, 0, 0}}},
        {'B', {{1, 1, 0, 0, 0, 0, 0, 0, 0, 0}}}
    };

    // for(auto const &cur : octaves)
    // {
    //     cout << cur.first << ": ";
    //     for(int i = 0; i < 10; i++)
    //     {
    //         cout << cur.second[i] << " ";
    //     }
    //     cout << endl;
    // }

    int cases;
    cin >> cases;
    while(cases--)
    {
        string song;
        cin >> song;
        // cout << song << " ";
        setup(); //init the elements to 0
        for(int i = 0; i < song.size(); i++)
        {
            // char cur = song[i];
            // cout << cur << ": ";
            array<int, 10> curOctave = octaves[song[i]];
            for(int j = 0; j < 10; j++)
            {
                // cout << curOctave[j] << " ";
                // cout << "j: " << j << endl;
                fingers[j] += curOctave[j];
            }
            // cout << endl;
        }

        for (int i = 0; i < 10; i++)
        {
            cout << fingers[i] << " ";
        }
        cout << endl;

    }
}

void setup()
{
    for(int i = 0; i < 10; i++)
    {
        fingers[i] = 0;
    }
}
