//DONE
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double score[1001][1001];

double solve(int anthony, int cora, double *probability)
{
	if(anthony == 0)
	{
		return 0.0;
	}
	if(cora == 0)
	{
		return 1.0;
	}

	if(score[anthony][cora] >= 0)
	{
		return score[anthony][cora];
	}

	return score[anthony][cora] = (probability[0] * solve(anthony, cora - 1, probability + 1)) + (1 - probability[0]) * solve(anthony - 1, cora, probability + 1);
}

int main()
{
	double game[2001];

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < 1001; i++)
	{
		fill(score[i], score[i] + 1001, -1.0);
	}

	for(int i = 0; i < n + m - 1; i++)
	{
		cin >> game[i];
	}

	cout << fixed << setprecision(6) << solve(n, m, game) << endl;


}