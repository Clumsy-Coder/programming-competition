#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve();
void checkCode(const int *genGuess);
void printAnswer();

const int totalPossibility = 10000;
bool notPossible[totalPossibility];     //indicate which code is not possible. true: code is not possible, false: code is possible
int curGuess [4];                       //user's guess. Each digit is in each element
int correct, misplaced;                 //num of correct and misplaced from user's guess
int generatedGuess[4];                  //used to generate all 10000 code combinations to check against

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        solve();
    }
}

void solve()
{
    fill(notPossible, notPossible + totalPossibility, false);
    int numGuesses; cin >> numGuesses;
    for(int cGuess = 0; cGuess < numGuesses; cGuess++)
    {   scanf("%1d%1d%1d%1d", curGuess, curGuess + 1, curGuess + 2, curGuess + 3);   //get the code user guessed.
        scanf("%1d/%1d", &correct, &misplaced);
        //go through 10000 code combinations
        for(generatedGuess[0] = 0; generatedGuess[0] < 10; generatedGuess[0]++)                //check thousand place, 1000
            for(generatedGuess[1] = 0; generatedGuess[1] < 10; generatedGuess[1]++)            //check hundred place, 100
                for(generatedGuess[2] = 0; generatedGuess[2] < 10; generatedGuess[2]++)        //check tens place, 10
                    for(generatedGuess[3] = 0; generatedGuess[3] < 10; generatedGuess[3]++)    //check ones place, 1
                    {
                        //current generated code.
                        checkCode(generatedGuess);
                    }
    }
    printAnswer();
}

void checkCode(const int *genGuess)
{
    int curGenCode = (genGuess[0] * 1000) +
                     (genGuess[1] * 100) +
                     (genGuess[2] * 10) +
                     (genGuess[3]);
    //check if the current generated number is possible
    if(!notPossible[curGenCode])
    {
        int c = 0;  //number of correct values
        int m = 0;  //number of correct misplaced values
        bool match[4] = {false};
        for(int i = 0; i < 4; i++)
        {
            if(genGuess[i] == curGuess[i]) //if the number match at the correct position
            {
                c++;
                match[i] = true;
            }
        }

        bool used[4] = {false};

        //if the number matchs at the INCORRECT position
        for(int i = 0; i < 4; i++)
        {
            if (match[i]) continue;     //ignore if the values at i are equal, since it was dealt with earlier
            for(int j = 0; j < 4; j++)
            {
                // i != j : to prevent looking at the same index. this was handled earlier
                // !used[j] && !match[j] : making sure the values are mapped 1 to 1.
                // curGuess[j] == genGuess[i] : check if the values are equal, even if it's misplaced
                if (i != j && (!used[j] && !match[j]) && (curGuess[j] == genGuess[i])) {
                    m++;
                    used[j] = true;
                    break;
                }
            }
        }

        //if the number for correct values is equal to the guess from the user OR
        //if the number of misplaced values is equal to the guess from the user, then it's a possible answer
        //else it is NOT possible for the current generated code to be the answer
        if(c != correct || m != misplaced)
        {
            notPossible[curGenCode] = true;
        }
    }
}

void printAnswer()
{
    int numCandidate = count(notPossible, notPossible + totalPossibility, false);
    if(numCandidate == 1)
    {
        int answer = distance(notPossible, find(notPossible, notPossible + totalPossibility, false));
        cout << setw(4) << setfill('0') << answer << endl;
    }
    else if(numCandidate == 0)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << "indeterminate" << endl;
    }
}
