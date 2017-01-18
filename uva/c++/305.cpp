//DONE

/*
	init "m" array elements to -1
	set m[0] = 2
	while there's input and the input is NOT 0
		print the value from solve function
			solve function
				if the input has already been calulated
					return the answer
				else
					create variable
						totalSize = 0	NOTE: this will either reduce OR be reset to 2 * k
											NOTE: it will be reset IF a good guy was killed before a bad guy
						prevKill = 0, 	NOTE: keeping track of the previous kill index
											NOTE: gets reset to 0 IF a good guy was killed before a bad guy
						killIndex = 0, 	NOTE: index that will be killed
						count = 0		NOTE: this will be used as the answer
					while true		NOTE: only breaks once an answer has been computed
						set  killIndex (count + prevKill) % totalSize
							it's starting by killing the first person.
						set prevKill =  killIndex
						if a good guy was killed before all the bad guys
							increment count by 1
							prevKill = 0;
							totalSize = 2 * k
							continue to the next iteration of the loop
						end if
						totalSize--		NOTE: this means a bad guy was killed without kill the good guy first
						if the totalSize IS k AND the answer > k		NOTE: answer is found
							update the array m[k - 1] to count + 1
								NOTE: the answer is count + 1 because it was being computed in index form.
							return the answer
						end if
					end while loop
				end if
			end solve function
	end while loop
*/

#include <iostream>

using namespace std;

int solve(int k);
int m[14];
int main()
{
	for(int i = 0; i < 14; i++){m[i] = -1;}

	m[0] = 2;
	int curCase;
	while(cin >> curCase && curCase)
	{
		cout << solve(curCase) << endl;
	}
}

int solve(int k)
{
	if(m[k - 1] != -1)
	{
		return m[k - 1];
	}

	int totalSize = 2 * k;
	long long prevKill = 0;
	long long  killIndex = 0;
	long long count = 0;
	while(true)
	{
		 killIndex = (count + prevKill) % totalSize;
		prevKill =  killIndex;
		if( killIndex < k)
		{
			count++;
			prevKill = 0;
			totalSize = 2 * k;
			continue;
		}
		totalSize--;
		if(totalSize == k && count > k)
		{
			m[k - 1] = count + 1;
			return count + 1;
		}
	}
}
