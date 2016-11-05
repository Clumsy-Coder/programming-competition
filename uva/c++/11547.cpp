//DONE
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long long answer = 0;
    int cases = 0;

    cin >> cases;

    for(unsigned int i = 0; i < cases; i++)
    {
        int value;
        cin >> value;

        answer = value * 567;
        answer = answer / 9;
        answer += 7492;
        answer = answer * 235;
        answer = answer / 47;
        answer -= 498;

        //getting tens digit formula from
        // http://stackoverflow.com/a/12795481/3053548
        cout << abs(answer / ((int) pow(10, 1)) % 10) << endl;
    }
}
