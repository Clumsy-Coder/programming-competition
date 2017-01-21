//DONE
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string input;
    while(getline(cin, input) && input.size())
    {
        for(int i = 0; i < input.size(); i++)
        {
            switch (input[i])
            {
                case 'Q': case 'A': case 'Z': case ' ': case '`':
                {
                    cout << input[i];
                    break;
                }
                default:
                {
                    cout << keyboard[keyboard.find(input[i]) - 1];
                    break;
                }
            }
        }
        cout << endl;
    }
}
