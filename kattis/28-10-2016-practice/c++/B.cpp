//IN PROGRESS
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

char table[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '.'};

int main()
{
    int offset;
    string word;

    while((cin >> offset >> word) && offset != 0)
    {
        reverse(word.begin(), word.end());
        string answer = "";
        for(int i = 0; i < word.size(); i++)
        {
            if(isalpha(word[i]))
            {
                answer += table[(word[i] - 'A' + offset) % 28];
                continue;
            }

            if(word[i] == '_')
            {
                answer += table[(26 + offset) % 28];
                continue;
            }

            if(word[i] == '.')
            {
                answer += table[(27 + offset) % 28];
                continue;
            }

        }

        cout << answer << endl;

    }

    return 0;
}
