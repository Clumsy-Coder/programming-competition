#include <iostream>

using namespace std;

int main()
{
	double length, width, thickness;
	while(cin >> length >> width >> thickness && (length && width && thickness))
	{
		cout << length << " " << width << " " << thickness << endl;
		//letter
		if( (length >= 125 || length <= 290) &&
			(width >= 90 || width <= 155) &&
			(thickness >= 0.25 || thickness <= 7.0))
		{
			cout << "letter" << endl;
		}
		//packet
		else if( (length >= 290 || length <= 380) &&
				 (width >= 155 || width <= 300) &&
			 	 (thickness >= 7.0 || thickness <= 50))
		{
			cout << "packet" << endl;
		}
		//parcel
		else if( (length >= 380 || length <= 2100) &&
				 (thickness * 2) + (width * 2) <= 2100)
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
