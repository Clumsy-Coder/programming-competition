//DONE

/*
    Ad-hoc
    get the dimensions and sort them (since the input can be given in any order).
    the smallest will range from 0.25 - 50 which is the thickness
    the largest will range from 125 - 380 which is the length
*/

#include <iostream>
#include <algorithm>

using namespace std;

double measurment [3];      //contains the length, width and thickness

int main()
{
    while(cin >> measurment[0] >> measurment[1] >> measurment[2] &&
           (measurment[0] && measurment[1] && measurment[2]))
    {
        // sorting will place will set the measurments in the proper. This
        // works because length and width will NOT intersect AND thickness
        // is the smallest value.
        // 1st element: thickness
        // 2nd element: length
        // 3rd element: width
        sort(measurment, measurment + 3);

        // letter dimensions:
        // length: 125 - 290
        // width: 90 - 155
        // thickness: 0.25 - 7

        // packet dimensions:
        // length: 290 - 380
        // width: 155 - 300
        // thickness: 7 - 50

        // letter
        if ((measurment[0] >= 0.25 && measurment[0] <= 7) &&    // thickness
            (measurment[1] >= 90 && measurment[1] <= 155) &&    // width
            (measurment[2] >= 125 && measurment[2] <= 290))     // length
        {
            cout << "letter";
        }
        // packet
        // check if the dimensions are >= min dimensions of letter
        // check if any of the dimensions <= max dimensions of letter
        // check if all the dimensions are within limits
        else if( (measurment[0] >= 0.25 && measurment[1] >= 90 && measurment[2] >= 125) &&
                 (measurment[0] > 7 || measurment[1] > 155 || measurment[2]) &&
                 (measurment[0] <= 50 && measurment[1] <= 300 && measurment[2] <= 380))
        {
            cout << "packet";
        }
        // parcel
        // check if the dimensions are >= min dimensions of letter
        // check if any of the dimensions <= max dimensions of letter
        // check if all the dimensions are within limits
        else if((measurment[0] >= 0.25 && measurment[1] >= 90 && measurment[2] >= 125) &&
                (measurment[0] > 50 || measurment[1] > 300 || measurment[2] > 380) &&
                (measurment[2] + 2 * (measurment[0] + measurment[1]) <= 2100) ) // girth
        {
            cout << "parcel";
        }
        else
        {
            cout << "not mailable";
        }
        cout << endl;
    }
}
