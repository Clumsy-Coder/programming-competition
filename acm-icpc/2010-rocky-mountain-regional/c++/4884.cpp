// DONE
/*
    Problem type: Geometry
    Data structure: string, double and int array (for direction)
    Algorithm: linear pass
    Summary: compute the internal area
             compute the total area using Pick's theorem

*/

#include <string>
#include <iostream>

using namespace std;

void solve();

// directions
// chaincode          0   1   2   3   4   5   6   7
const int dirX[8] = { 0, -1, -1, -1,  0,  1,  1,  1 };
const int dirY[8] = { 1,  1,  0, -1, -1, -1,  0,  1 };
string chainCode;

int main()
{
    while(cin >> chainCode)
    {
        solve();
    }
}

void solve()
{
    // using Pick's theorem
    // area = i + (boundary / 2) - 1
    // 2 * area = 2 * i + boundary - 2      to avoid floating numbers

    double interiorArea = 0.0;
    double x1 = 0.0, y1 = 0.0;      // start at point 0,0
    double x2, y2;                  // next point

    for(unsigned long long i = 0; i < chainCode.size() - 1; i++)
    {
        // next point
        x2 = x1 + dirX[chainCode[i] - '0'];
        y2 = y1 + dirY[chainCode[i] - '0'];
        // calc area
        interiorArea += (x1 * y2) - (x2 * y1);
        // set cur point to next point
        x1 = x2;
        y1 = y2;
    }

    interiorArea /= 2;
    double area = (2 * interiorArea) + chainCode.size() + (2 * 1);
    cout << (long long)area / 2 << endl;
}
