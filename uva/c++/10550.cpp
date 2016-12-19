//DONE
#include <iostream>

using namespace std;

int main()
{

    int init, first, second, third;

    while(cin >> init >> first >> second >> third && 
	  (init || first || second || third))
    {
	//1080 because 2 full rotations clockwise (720 degrees) + 
	// 1 full rotation counter-clockwise (360 degrees)
        long long answer = 1080;

	// multiply by 9 because 40 * 9 = 360
	// there's 40 marks on a combination lock
	
	// using the difference because we need to get the value
	// on how many degrees needs to be turned from that point on.
	answer += (init - first) > 0 ? (init - first) * 9 : (init - first + 40) * 9;
	answer += (second - first) > 0 ? (second - first) * 9 : (second - first + 40) * 9;
	answer += (second - third) > 0 ? (second - third) * 9 : (second - third + 40) * 9;
	
	cout << answer << endl;

    }

    return 0;
}
