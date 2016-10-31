//IN PROGRESS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    /*
        get the input. offset and word
        reverse the word
        for size word
            if current char is _
                int temp = 91
            else if current char is .
                int temp = 92
            else
                int temp = (int)word[i]

            string newStr
            if int temp + offset >= 91
                if temp + offset == 91
                    newStr += '_'
                if temp + offset == 92
                    newStr += '.'
                else
                    temp += offset
                    newStr += ((char)temp % 28) + 56
            else
                newStr += (char)temp + offset

        print newStr
    */

    int offset;
    string word;

    while((cin >> offset >> word) && offset != 0)
    {
        if(offset == 0)
        {
            break;
        }
        reverse(word.begin(), word.end());
        string tempstr;
        bool isTrue = false;
        for(int i = 0; i < word.size(); i++)
        {
            int temp = 0;
            if(word[i] == '_')
            {
                temp = 91;

            }
            else if(word[i] == '.')
            {
                temp = 92;
            }
            else
            {
                temp = word[i];
            }

            if(temp + offset >= 91)
            {
                //if temp + offset == 91
                if(temp + offset == 91)
                {
                    tempstr += '_';
                }
                //if temp + offset == 28
                else if(temp + offset == 92)
                {
                    tempstr += '.';
                }
                else
                {
                    temp += offset;
                    tempstr += ((char)temp % 28) + 56;
                }

            }

            else
            {
                tempstr += (char)temp + offset;
            }

        }

        cout << tempstr << endl;

    }

    return 0;
}
