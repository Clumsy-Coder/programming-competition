#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){

	int fieldNum = 0;
	int row = 0;
	int col = 0;
	int const mine = -9000;
	int mineField [105][105];




	while(true){
		cin >> row >> col;

		if(row == 0 && col == 0){
			break;
		}

		if(fieldNum != 0){cout << endl;}
		fieldNum++;
		for (int i = 0; i < row; i++)
		{
			string curRow = "";
			cin >> curRow;
			for (int j = 0; j < col; j++)
			{
				if(curRow[j] == '*')
				{
					mineField[i + 1][j + 1] = mine;

				}

				else
				{
					mineField[i + 1][j + 1] = 0;
				}
			}
		}

		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				if(mineField[i][j] < 0)
				{
					mineField[i][j+1]++;
					mineField[i][j-1]++;
					mineField[i + 1][j]++;
					mineField[i - 1][j]++;
					mineField[i + 1][j + 1]++;
					mineField[i - 1][j - 1]++;
					mineField[i - 1][j + 1]++;
					mineField[i + 1][j - 1]++;
				}
			}
		}

		cout << "Field #" << fieldNum << ":" << endl;
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				if(mineField[i][j] < 0){
					cout << "*";
				}

				else{
					cout << mineField[i][j];
				}

			}

			cout << endl;
		}



	}

	return 0;
}