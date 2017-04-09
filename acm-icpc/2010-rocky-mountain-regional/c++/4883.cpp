// DONE
/*
    Problem type: Ad-hoc
    Data structure: 1D array
    Algorithm: linear pass
    Summary: find the largest pitch and check if the rope length satisfies the
             conditions.
             conditions: - at least two climbers.
                         - rope length is at least half
                           the length of total pitch length.
*/

#include <iostream>

using namespace std;

int numPitch, pitchLength [101];

int solve(int ropeLength);

int main()
{
    while(cin >> numPitch && numPitch)
    {
        for(int i = 0; i < numPitch; i++)
        {
            cin >> pitchLength[i];
        }

        cout << solve(50) << " "
             << solve(60) << " "
             << solve(70) << endl;
    }
}

int solve(int ropeLength)
{
    int maxPitchLength = -1;
    int totalPitchLength = 0;
    for(int i = 0; i < numPitch; i++)
    {
        maxPitchLength = max(maxPitchLength, pitchLength[i]);
        totalPitchLength += pitchLength[i];
    }

    // rope must be at least half the total pitch length.
    // double the length, to avoid floating numbers
    // there must be at least two climbers.
    int numClimbers = ropeLength / maxPitchLength;
    if(numClimbers >= 2 && ropeLength >= 2 * totalPitchLength)
    {
        // +1 because there's a climber at the bottom
        return numClimbers + 1;
    }
    else
    {
        return 0;
    }
}
