//DONE
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int ppl;
    bool secondLoop = false; //to deal with presentation error. if there's more than one case to deal with.
    while(cin >> ppl && ppl)
    {
        if(secondLoop){cout << endl;}
        map<string, double> gifts;
        vector<string> insertionOrder; //to keep track of the insertion order
        for(int i = 0; i < ppl; i++)
        {
            string name;
            cin >> name;
            gifts[name] = 0;
            insertionOrder.push_back(name);
        }
        for(int n = 0; n < ppl; n++)
        {
            string name; int money; int recievers;
            cin >> name >> money >> recievers;
            if(recievers == 0) continue;
            gifts[name] -= money - (money % recievers);

            for(int i = 0; i < recievers; i++)
            {
                string curName;
                cin >> curName;
                gifts[curName] += (money / recievers);
            }
        }
        for(auto const &curName : insertionOrder)
        {
            cout << curName << " " << gifts[curName] << endl;
        }
        secondLoop = true;
    }
}
