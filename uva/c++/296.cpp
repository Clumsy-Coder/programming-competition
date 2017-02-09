#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve();
void checkCode(const int *genGuess);
void printAnswer();

const int totalPossibility = 10000;
bool notPossible[totalPossibility];     //indicate which code is not possible
int curGuess [4];                       //user's guess
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
                        //current generate code.
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
    //check if the current generated number is not marked as not possible
    if(!notPossible[curGenCode])
    {
        int c = 0;
        int m = 0;
        bool match[4] = {false, false, false, false};
        for(int i = 0; i < 4; i++)
        {
            if(genGuess[i] == curGuess[i]) //if the number match at the correct position
            {
                c++;
                match[i] = true;
            }
        }
        //if the number matchs at the INCORRECT position
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                //check the ones that are misplaced, NOT the ones that are correct
                // thats what (genGuess[i] != curGuess[i]) is used for
                if(genGuess[i] != curGuess[i] && (genGuess[i] == curGuess[j] && !match[j]))
                {
                    m++;
                    match[j] = true;
                }
            }
        }

        //if the number for correct values is equal to the guess from the user OR
        //if the number of misplaced values is equal to the guess from the user, then it's a possible answer
        //else it is not possible for the current generated code to be the answer
        if(c != correct || m != misplaced)
        {
            notPossible[curGenCode] = true;
        }
    }
}

void printAnswer()
{
    int answer;
    int numCandidate = 0;
    //count the number of generated is possible
    for(int i = 0; i < totalPossibility; i++)
    {
        //if the code is possible
        if(!notPossible[i])
        {
            numCandidate++;
            answer = i;
        }
    }
    if(numCandidate == 1)
    {
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
