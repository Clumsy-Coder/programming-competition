#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>


// Howard Cheng's code
//-------------------------------------------------------------------------//
/*
 * Area of a polygon
 *
 * Author: Howard Cheng
 * Reference:
 *   http://www.exaflop.org/docs/cgafaq/cga2.html
 *
 * This routine returns the SIGNED area of a polygon represented as an
 * array of n points (n >= 1).  The result is positive if the orientation is
 * counterclockwise, and negative otherwise.
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

struct Point {
  double x, y;
};

double area_polygon(Point polygon[], int n)
{
  double sum = 0.0;

  for (int i = 0; i < n-1; i++) {
    sum += polygon[i].x * polygon[i+1].y - polygon[i].y * polygon[i+1].x;
  }
  sum += polygon[n-1].x * polygon[0].y - polygon[n-1].y * polygon[0].x;
  return sum/2.0;
}

// END Howard Cheng's code
//-------------------------------------------------------------------------//

void solve();
void generatePolygon();

//                    0   1   2   3   4   5   6   7
const int dirX[8] = { 0, -1, -1, -1,  0,  1,  1,  1 };
const int dirY[8] = { 1,  1,  0, -1, -1, -1,  0,  1 };
string chainCode;
// vector<pair<long long, long long>> polygon;
// Point polygon [100001] ;

int main()
{
    while(cin >> chainCode)
    {
        generatePolygon();
        cout << "-------------------\n";
    }
}

void generatePolygon()
{
    // Point *polygon = new Point[chainCode.size()];
    Point polygon[chainCode.size() + 1];
    polygon[0].x = 0;
    polygon[0].y = 0;
    double minX = LONG_MAX;
    double minY = LONG_MAX;
    cout << "chaincode size: " << chainCode.size() << endl;
    cout << "x:\t" << polygon[0].x << "\ty:\t" << polygon[0].y << endl;
    for(int i = 0; i < chainCode.size(); i++)
    {
        if(i == chainCode.size() + 1) break;
        Point prev = polygon[i];
        double x = prev.x + dirX[chainCode[i] - '0'];
        double y = prev.y + dirY[chainCode[i] - '0'];
        polygon[i + 1].x = x;
        polygon[i + 1].y = y;
        minX = min(minX, x);
        minY = min(minY, y);
        cout << "x:\t" << x << "\ty:\t" << y << endl;
    }

    // cout << "minX: " << minX << "\n" << "minY: " <<  minY << endl;

    minX = abs(minX);
    minY = abs(minY);
    // translate the polygon so all the points are positive
    // for(int i = 0; i < chainCode.size(); i++)
    // {
    //     polygon[i].x += minX;
    //     polygon[i].y += minY;
    // }
    cout << "area: " << area_polygon(polygon, chainCode.size()) << endl;

    // delete[] polygon;
}
