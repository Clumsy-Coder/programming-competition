//DONE

/*
	create an array size of 102 x 102 int
	while there's input
		for each row get the input character by charcter 
			if the char is * then it's a mine
				(note: insert at i + 1 and j + 1, to have a space around the array, to avoid bound checking errors)
				insert the 'mine' (big value below 0) value at that col
			else
				insert a zero
		iterate through the array. Row
			iterate through the array. Col
				if the current element is less than 0 (mine)
					then increment by 1 around the mine.
		display the array

*/


#include <iostream>
#include <string>

using namespace std;

int fieldNum = 0;			//indicating if there's more than one case when displaying the result
int row = 0;
int col = 0;
int const mine = -9000;		/*
								used for indicating there's a mine.
								if they're two mines near by
								incrementing the value won't change the
								representation from mine to a number when it's being displayed
								ex:
									.**
									.*.
								the result would be
									2**
									2*3
							*/
int mineField [102][102];	//102 is for adding extra padding, so there's no out of bounds error

void setup();
void solve();
void print();

int main()
{
	while(cin >> row >> col && (row && col)) //while there's input and they're NOT 0
	{
		if(fieldNum != 0){cout << endl;}	fieldNum++; 	//NOTE: if this is a second case or more

		setup();
		solve();
		print();
	}
}

void setup()
{
	for (int i = 0; i < row; i++)
	{
		string curRow;
		cin >> curRow;
		for (int j = 0; j < col; j++)
		{
			if(curRow[j] == '*')
			{
				mineField[i + 1][j + 1] = mine;		//i + 1 AND j + 1 so there's padding around the grid
			}
			else
			{
				mineField[i + 1][j + 1] = 0;		//i + 1 AND j + 1 so there's padding around the grid
			}
		}
	}
}

void solve()
{
	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
		{
			if(mineField[i][j] < 0)	//increment by 1 around the mine
			{
				mineField[i][j+1]++;		//right
				mineField[i][j-1]++;		//left
				mineField[i + 1][j]++;		//down
				mineField[i - 1][j]++;		//up
				mineField[i + 1][j + 1]++;	//bottom right
				mineField[i - 1][j - 1]++;	//bottom left
				mineField[i - 1][j + 1]++;	//top right
				mineField[i + 1][j - 1]++;	//top left
			}
		}
	}
}

void print()
{
	cout << "Field #" << fieldNum << ":" << endl;
	for (int i = 1; i <= row; ++i)
	{
		for (int j = 1; j <= col; ++j)
		{
			if(mineField[i][j] < 0)
			{
				cout << "*";
			}
			else
			{
				cout << mineField[i][j];
			}
		}
		cout << endl;
	}
}
