#include <iostream>

using namespace std;

int main()
{
	double length, width, thickness;
	while(cin >> length >> width >> thickness)
	{
		//letter
		if( (length >= 125 || length <= 290) &&
			(width >= 90 || width <= 155) && 
			(thickness >= 0.25 || thickness <= 7.0))
		{
			cout << "letter" << endl;
		}
		//packet
		else if()
		{
			cout << "packet" << endl;
		}
		//parcel
		else if()
		{
			cout << "parcel" << endl;
		}
		//not mailable
		else
		{
			cout << "not mailable" << endl;
		}
	}
}