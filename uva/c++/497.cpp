//DONE
/*
 * Longest Ascending Subsequence problem. (STRICTLY ascending)
 * Use Howard Cheng code to determine the answer
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//Howard Cheng longest subsequence code

//ignores duplicate values
int sasc_seq(int A[], int n, int S[])
{
    vector<int> last(n+1), pos(n+1), pred(n);
    if (n == 0)
    {
        return 0;
    }

    int len = 1;
    last[1] = A[pos[1] = 0];

    for (int i = 1; i < n; i++)
    {
        int j = lower_bound(last.begin()+1, last.begin()+len+1, A[i]) - last.begin();
        pred[i] = (j-1 > 0) ? pos[j-1] : -1;
        last[j] = A[pos[j] = i];
        len = max(len, j);
    }

    int start = pos[len];
    for (int i = len-1; i >= 0; i--)
    {
        S[i] = A[start];
        start = pred[start];
    }

    return len;
}

//End Howard Cheng longest subsequence code
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//
//-------------------------------------------------------------------------//

int main(void)
{
    int *A, *S, n, i, k;
    int cases; cin >> cases; cin.ignore(); cin.ignore();
    while(cases--)
    {
        string value;
        vector<int> missles;
        //read until there's a blank line.
        //Considered to be the end of input for current case
        while(getline(cin, value))
        {
            if(value.empty())
            {
                break;
            }
            missles.push_back(stoi(value));
        }
        n = missles.size();
        A = new int[n];
        S = new int[n];
        copy(missles.begin(), missles.end(), A);

        k = sasc_seq(A, n, S);
        cout << "Max hits: " << k << endl;
        for (i = 0; i < k; i++)
        {
            cout << S[i] << endl;
        }
        delete[] A;
        delete[] S;

        if(cases){cout << endl;}
    }
    return 0;
}
