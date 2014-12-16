#include <bits/stdc++.h>

using namespace std;

int main()
{
	int U, I;
	cin >> U;
	I = U;
	while(U--)
	{
		int N, f;
		cin >> N;
		string s;
		cin >> s;
		vector<vector<int> > A(N,vector<int>() );
		if (s == "down")
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cin >> f;
					A[i].push_back(f);
				}
			}
		}
		else if (s == "right")
		{
//			cout << "right" << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					A[i].push_back(0);
				}
			}
	
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					int w;
					cin >> w;
					A[j][N-i-1] = w;
				}
			}
		}
		else if (s == "left")
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					A[i].push_back(0);
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = N-1; j >= 0; j--)
				{
					int w;
					cin >> w;
					A[j][i] = w;
				}
			}
		}
		else if (s == "up")
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					A[i].push_back(0);
				}
			}
			for (int i = N-1; i >= 0; i--)
			{
				for (int j = 0; j < N; j++)
				{
					int w;
					cin >> w;
					A[i][j] = w;
				}
			}
		}
		for(int i = N-1; i >= 0; i--)
		{
			for(int j = 0; j < N; j++)
			{
				int a = 0, b = 0, k = 0, l = 0;
				for (int h = i; h >= 0; h--)
				{
					if (A[h][j] != 0)
						if (k == 0)
						{
							a = A[h][j];
							A[h][j] = 0;
							k++;
							l = h;
						}
						else
						{
							b = A[h][j];
							A[h][j] = 0;
							l = h;
							break;
						}
				}
				if ((k > 0)&&(a == b))
				{
					A[i][j] = 2*a;
				}
				else if ((k > 0)&&(b != 0)&&(a != b))
				{
					A[i][j] = a;
					A[l][j] = b;
				}
				else if (k > 0)
				{
					A[i][j] = a;
				}
			}
		}
		cout << "Case #" << I-U << ":" << endl;
		if (s == "down")
		{
			for (int i = 0 ; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cout << A[i][j] << " ";
				}
				cout << endl;
			}
		}
		else if (s == "right")
		{
			for (int i = N-1 ; i >= 0; i--)
			{
				for (int j = 0; j < N; j++)
				{
					cout << A[j][i] << " ";
				}
				cout << endl;
			}

		}
		else if (s == "left")
		{
			for (int i = 0 ; i < N; i++)
			{
				for (int j = N-1; j >= 0; j--)
				{
					cout << A[j][i] << " ";
				}
				cout << endl;
			}

		}
		else if (s == "up")
		{
			for (int i = 0 ; i < N; i++)
			{
				for (int j = N-1; j >= 0; j--)
				{
					cout << A[N-i-1][N-j-1] << " ";
				}
				cout << endl;
			}

		}
	}
	return 0;
}
