// Narendra Nalli

#include <bits/stdc++.h>

using namespace std;

bool recOpen(vector<vector<bool> >& A, vector<vector<bool> >& B, int a, int b, int N)
{
	int c = 0, d = 0;
	if (A[a][b] == true)
		return false;
	if ((a-1 >= 0)&&(b-1 >= 0)&&(A[a-1][b-1] == false))
	{
		c++;
		d++;
	}
	else if ((a-1 >= 0)&&(b-1 >= 0))
		d++;
	if ((a-1 >= 0)&&(A[a-1][b] == false))
	{
		c++;
		d++;
	}
	else if (a-1 >= 0)
		d++;
	if ((a-1 >= 0)&&(b+1 < N)&&(A[a-1][b+1] == false))
	{
		c++;
		d++;
	}
	else if ((a-1 >= 0)&&(b+1 < N))
		d++;
	if ((b-1 >= 0)&&(A[a][b-1] == false))
	{
		c++;
		d++;
	}
	else if (b-1 >= 0)
		d++;
	if ((b+1 < N)&&(A[a][b+1] == false))
	{
		c++;
		d++;
	}
	else if (b+1 < N)
		d++;
	if ((a+1 < N)&&(b-1 >= 0)&&(A[a+1][b-1] == false))
	{
		c++;
		d++;
	}
	else if ((a+1 < N)&&(b-1 >= 0))
		d++;
	if ((a+1 < N)&&(A[a+1][b] == false))
	{
		c++;
		d++;
	}
	else if (a+1 < N)
		d++;
	if ((a+1 < N)&&(b+1 < N)&&(A[a+1][b+1] == false))
	{
		c++;
		d++;
	}
	else if ((a+1 < N)&&(b+1 < N))
		d++;
	bool hh;
	if (c == d)
	{
		B[a][b] = true;
		if ((a-1 >= 0)&&(b-1 >= 0))
		{
			if (B[a-1][b-1] == false)
			{
				B[a-1][b-1] = true;
				hh = recOpen(A, B, a-1, b-1, N);
			}
		}
		if (a-1 >= 0)
		{
			if (B[a-1][b] == false)
			{
				B[a-1][b] = true;
				hh = recOpen(A, B, a-1, b, N);
			}
		}
		if ((a-1 >= 0)&&(b+1 < N))
		{
			if (B[a-1][b+1] == false)
			{
				B[a-1][b+1] = true;
				hh = recOpen(A, B, a-1, b+1, N);
			}
		}
		if (b-1 >= 0)
		{
			if (B[a][b-1] == false)
			{
				B[a][b-1] = true;
				hh = recOpen(A, B, a, b-1, N);
			}
		}
		if (b+1 < N)
		{
			if (B[a][b+1] == false)
			{
				B[a][b+1] = true;
				hh = recOpen(A, B, a, b+1, N);
			}
		}
		if ((a+1 < N)&&(b-1 >= 0))
		{
			if (B[a+1][b-1] == false)
			{
				B[a+1][b-1] = true;
				hh = recOpen(A, B, a+1, b-1, N);
			}
		}
		if (a+1 < N)
		{
			if (B[a+1][b] == false)
			{
				B[a+1][b] = true;
				hh = recOpen(A, B, a+1, b, N);
			}
		}

		if ((a+1 < N)&&(b+1 < N))
		{
			if (B[a+1][b+1] == false)
			{
				B[a+1][b+1] = true;
				hh = recOpen(A, B, a+1, b+1, N);
			}
		}
	}
	else
		return false;
	return true;
}


int main()
{
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++)
	{
		int N;
		cin >> N;
		char c;
		vector<vector <bool> > A(N, vector<bool>(N));
		vector<vector<bool> > B(N, vector<bool>(N));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> c;
				if (c == '*')
				{
					A[i][j] = true;
					B[i][j] = true;
				}
				else
				{
					A[i][j] = false;
					B[i][j] = false;
				}
			}
		}
/*		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << B[i][j];
			cout << endl;
		}
*/
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (B[i][j] == false)
				{
					bool h = recOpen(A, B, i, j, N);
					if (h == true)
						count++;
				}
			}
		}
//		cout << endl;
/*		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << B[i][j];
			cout << endl;
		}
*/		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (B[i][j] == false)
					count++;
			}
		}
		
		cout << "Case #" << x << ": " << count << endl;
	}
	return 0;
}
