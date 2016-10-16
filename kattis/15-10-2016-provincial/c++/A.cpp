//DONE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main()
{
    int cases = 0;
    vector <int> list;

    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        long long value = 0;
        int numOnes = 0;
        cin >> value;
        value = value * 10;
        //int tempValue = value * 10;

        while(value / 10 > 0)
        {
            int tempValue = value / 10;
            while(tempValue > 0)
            {
                if(tempValue % 2 == 0)
                {
                    tempValue = tempValue / 2;
                }

                else if(tempValue % 2 == 1)
                {
                    numOnes++;
                    tempValue = tempValue / 2;
                }

            }

            list.push_back(numOnes);
            numOnes = 0;
            value = value/10;
        }



        sort(list.begin(), list.end());
        /*
        for(unsigned int k = 0; k < list.size(); k++)
        {
            cout << list[k] << " ";
        }

        cout << endl;
        */
        cout << list[list.size()-1] << endl;

        list.clear();
    }



    return 0;
}
