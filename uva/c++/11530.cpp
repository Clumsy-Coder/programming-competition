#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int cases = 0;
    cin >> cases;

    for(int i = 0; i < cases + 1; i++)
    {
        string line;
        getline(cin, line);
        if(i == 0 )continue;
        long answer = 0;

        for(int j = 0; j < line.size(); j++)
        {
            //cout << line[j] << " ";
            switch(line[j])
            {
                case 'a': {answer += 1; break;}
                case 'b': {answer += 2; break;}
                case 'c': {answer += 3; break;}
                case 'd': {answer += 1; break;}
                case 'e': {answer += 2; break;}
                case 'f': {answer += 3; break;}
                case 'g': {answer += 1; break;}
                case 'h': {answer += 2; break;}
                case 'i': {answer += 3; break;}
                case 'j': {answer += 1; break;}
                case 'k': {answer += 2; break;}
                case 'l': {answer += 3; break;}
                case 'm': {answer += 1; break;}
                case 'n': {answer += 2; break;}
                case 'o': {answer += 3; break;}
                case 'p': {answer += 1; break;}
                case 'q': {answer += 2; break;}
                case 'r': {answer += 3; break;}
                case 's': {answer += 4; break;}
                case 't': {answer += 1; break;}
                case 'u': {answer += 2; break;}
                case 'v': {answer += 3; break;}
                case 'w': {answer += 1; break;}
                case 'x': {answer += 2; break;}
                case 'y': {answer += 3; break;}
                case 'z': {answer += 4; break;}
                case ' ': {answer += 1; break;}
            }
        }
        //cout << endl;
        cout << "Case #" << i << ": " << answer << endl;

    }

    return 0;
}
