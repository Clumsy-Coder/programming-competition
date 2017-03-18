//DONE
#include <iostream>

using namespace std;

const int MAX_H = 20;
const int MAX_W = 20;

int image [MAX_H][MAX_W] ;
int kernel [MAX_H][MAX_W] ;
int final [MAX_H][MAX_W] ;
int H, W;		//image
int N, M;		//kernel

int main()
{
	while (cin >> H >> W >> N >> M)
	{
		//read image matrix
		for(int i = 0; i < H; i++)
			for(int k = 0; k < W; k++)
				cin >> image[i][k];

		//read kernel
		for(int i = 0; i < N; i++)
			for(int k = 0; k < M; k++)
				cin >> kernel[i][k];

		//solve
		for(int i = 0; i < H - N + 1; i++)
		{
			for(int k = 0; k < W - M + 1; k++)
			{
				int temp = 0;
				for(int keH = N; keH > 0; keH--)
				{
					for(int keW = M; keW > 0; keW--)
					{
						temp += kernel[keH - 1][keW - 1 ] * image[i + (N - keH)][k + (M - keW)];
					}
				}
				final[i][k] = temp;
			}
		}
		//print
		for(int i = 0; i < H - N + 1; i++)
		{
			for(int k = 0; k < W - M + 1; k++)
			{
				cout << final[i][k] << " ";
			}
			cout << endl;
		}
	}
}