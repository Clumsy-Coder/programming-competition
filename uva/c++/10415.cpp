//DONE

/*
    NOTE: compile in c++11

    create a map. key is the song note and value is an array of ints [10].
        NOTE: the value is an array contains which finger was pressed at that note
    get number of cases
    while there's a case to work on
        get the song. even if it's blank
        init the fingers[10] elements to 0. Array is global
        create a std array of int with 10 elments. at the moment it's empty.
            NOTE: it will be used to indicate the previous note played
            NOTE: variable is called "prevOctave"
        iterate through the song, one character at a time
            create a std array of int with 10 elements.
                NOTE: contains the finger configuration of the current note being played.
                NOTE: variable is called "curOctave"
            if this is the first note being played
                for loop up to 10, starting at 0
                    increment current finger by the finger configuration value "curOctave"
                        NOTE: use the fingers array
                end for loop
            else
                for loop up to 10, starting at 0
                    if the current finger of the previous note is not pressed
                        increment current finger by the finger configuration value "curOctave"
                            NOTE: use the fingers array
                end for loop
            end if
            set the "prevOctave" to "curOctave"
        end loop
    end while loop
*/

#include <iostream>
#include <map>
#include <array>

using namespace std;

void setup();

int fingers [10]; //10 fingers. each index contains # of times that finger was pressed.
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

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    while(cases--)
    {
        string song;
        getline(cin, song);
        setup(); //init the finger array elements to 0
        array<int, 10> prevOctave;
        for(int i = 0; i < song.size(); i++)
        {
            array<int, 10> curOctave = octaves[song[i]];
            if(i == 0)
            {
                for(int j = 0; j < 10; j++)
                {
                    fingers[j] += curOctave[j];
                }
            }
            else
            {
                for(int j = 0; j < 10; j++)
                {
                    if(prevOctave[j] - curOctave[j] == -1)
                    {
                        fingers[j] += curOctave[j];
                    }
                }
            }
            prevOctave = curOctave;
        }
        for (int i = 0; i < 9; i++)
        {
            cout << fingers[i] << " ";
        }
        cout << fingers[9] << endl;
    }
}

void setup()
{
    for(int i = 0; i < 10; i++)
    {
        fingers[i] = 0;
    }
}
