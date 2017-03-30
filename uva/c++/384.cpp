//IN PROGRESS
#include <iostream>

using namespace std;

bool isSlump(int start, int end);
bool isSlimp(int start, int end);
bool isSlurpy();

string text;

int main()
{
    int cases; cin >> cases;
    cout << "SLURPYS OUTPUT" << endl;
    while(cases--)
    {
        cout << (isSlurpy() ? "YES" : "NO") << endl;
    }
    cout << "END OF OUTPUT" << endl;
}

bool isSlurpy()
{
    bool answer = false;
    cin >> text;

    for(int i = 0; i < text.size(); i++)
    {
        answer = isSlump(i + 1, text.size() - 1) && isSlimp(0, i);

        if(answer) return answer;
    }

    return answer;
}

bool isSlump(int start, int end)
{

}

bool isSlimp(int start, int end)
{

}
