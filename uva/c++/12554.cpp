//DONE
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string song [] = {"Happy", "birthday", "to", "you",
                      "Happy", "birthday", "to", "you",
                      "Happy", "birthday", "to", "Rujia",
                      "Happy", "birthday", "to", "you"};
    vector <string> names(n);

    for(int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    bool done = false;
    for(int w = 0, p = 0; w < 16 || !done; p++, w++)
    {
        w %= 16;
        cout << names[p] << ": " << song[w] << endl;
        if(p + 1 == n)
        {
            done = true;
            p = -1;
        }
    }
}
