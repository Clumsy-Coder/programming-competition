#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases = 0;
    cin >> cases;

    for(int i =0; i < cases; i++)
    {
        int rows = 0;
        int cols = 0;

        cin >> rows >> cols;

        char array[rows + 1][cols + 1];

        for(int k = 0; k < rows; k++)
        {
            string rowData;
            cin >> rowData;

            for (int j = 0; j < rowData.size(); j++)
            {
                array[k][j] = rowData[j];

            }

        }

        cout << "Test " << i + 1 << endl;
        for(int k = rows - 1; k >= 0; k--)
        {
            for(int j = cols - 1 ; j >= 0; j--)
            {
                cout << array[k][j];

            }

            cout << endl;
        }

    }

    return 0;
}
