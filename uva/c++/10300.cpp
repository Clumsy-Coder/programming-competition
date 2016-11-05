//DONE
#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;

    while(cases--)
    {
        long long answer = 0;
        int farmers;
        cin >> farmers;
        for(int i = 0; i < farmers; i++)
        {
            int farmyard;
            int animals;
            int envFriend;

            cin >> farmyard >> animals >> envFriend;
            answer += farmyard * envFriend;
        }

        cout << answer << endl;

    }

    return 0;
}
