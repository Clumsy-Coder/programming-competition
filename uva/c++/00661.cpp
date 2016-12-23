//DONE
#include <iostream>

using namespace std;

int main()
{
    int devices, numOp, cap;
    long sequence = 1;
    while(cin >> devices >> numOp >> cap && (devices && devices && numOp))
    {
        int consumption[devices]; bool status[devices];
        bool fuseBlown = false;
        for(int i = 0; i < devices; i++)
        {
            cin >> consumption[i];
            status[i] = false;
        }
        long curConsumption = 0; long maxConsumption = 0;
        for(int i = 0; i < numOp; i++)
        {
            long op; cin >> op;
            if(status[op - 1] == false)
            {
                curConsumption += consumption[op - 1];
                status[op - 1] = true;
            }
            else
            {
                curConsumption -= consumption[op - 1];
                status[op - 1] = false;
            }
            if(curConsumption > cap)
            {
                fuseBlown = true;
            }
            else
            {
                if(curConsumption > maxConsumption) maxConsumption = curConsumption;
            }
        }
        if(fuseBlown)
        {
            cout << "Sequence " << sequence++ << endl;
            cout << "Fuse was blown." << endl << endl;
        }
        else
        {
            cout << "Sequence " << sequence++ << endl;
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << maxConsumption << " amperes." << endl << endl;
        }
    }
}
