#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, N, w;
	cin >> T;
	w = T;
	while(T--)
	{
		cin >> N;
		int C;
		vector<vector<int> > B(N,vector<int>(N));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> B[i][j];
			}
		}
		vector<bool> A(N*N + 1, false);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((i-1 >= 0)&&(B[i-1][j] == B[i][j]+1))
				{
					A[B[i][j]] = true;
				}
				if ((i+1 < N)&&(B[i+1][j] == B[i][j]+1))
				{
					A[B[i][j]] = true;
				}
				if ((j-1 >= 0)&&(B[i][j-1] == B[i][j]+1))
				{
					A[B[i][j]] = true;
				}
				if ((j+1 < N)&&(B[i][j+1] == B[i][j]+1))
				{
					A[B[i][j]] = true;
				}	
			}
		}
/*		int o = 0;
		for (int i = 1; i < N*N+1; i++)
		{
			cout << i << "	::	" << A[i] << endl;
		}
*/
		vector<int> CS(N*N+1,0);
		int count = 0, max1 = 0, max_i;
		for (int i = 1; i <= N*N; i++)
		{
			if ((A[i])&&(!A[i-1]))
			{
				count = 2;
				int j = i+1;
				while(A[j])
				{
					count++;
					j++;
				}
				CS[i] = count;
				count--;
			}
			else if (A[i])
			{
				CS[i] = count;
				count--;
			}
			else if (!A[i])
			{
				CS[i] = 1;
				if (count != 1)
				{
//					cout << "Check it, it has to be 1" << count << endl;
					count = 1;
				}
			}
//			cout << A[i] << " " << CS[i] << endl;
			if(CS[i] > max1)
			{
				max1 = CS[i];
				max_i = i;
			}
		}

		cout << "Case #" << (w - T) << ": " << max_i << " " << max1 << endl;
	}
	return 0;
}
