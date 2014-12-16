#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, count = 0;
	bool marked = false;
	cin >> n;
	cin >> m;
	vector<vector<char> > A(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		marked = false;
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];
			if ((marked == false)&&(j == m-1)&&((A[i][j] == 'R')||(A[i][j] == 'G')))
			{	
				count++;
				if (A[i][j] == 'R')
					A[i][j] = '.';
				else
					A[i][j] = 'B';
			}
			else if ((marked == false)&&((A[i][j] == 'R')||(A[i][j] == 'G')))
			{
				marked = true;
				if (A[i][j] == 'R')
					A[i][j] = '.';
				else
					A[i][j] = 'B';
			}
			else if ((marked == true)&&((A[i][j] == '.')||(A[i][j] == 'B')||(j == m-1)))
			{
				count++;
				if (j == m-1)
				{
					if (A[i][j] == 'G')
						A[i][j] = 'B';
					else
						A[i][j] = '.';
				}
				marked = false;
			}
			else if ((marked == true)&&((A[i][j] == 'R')||(A[i][j] == 'G')))
			{
				if (A[i][j] == 'R')
					A[i][j] = '.';
				else
					A[i][j] = 'B';
			}
		}
	}
/*	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j];
		cout << endl;
	}
*/
	for (int i = 0; i < m; i++)
	{
		marked = false;
		for (int j = 0; j < n; j++)
		{
			
			if ((marked == false)&&(j == n-1)&&((A[j][i] == 'B')||(A[j][i] == 'G')))
			{
				count++;
				A[j][i] = '.';
			}
			else if ((marked == false)&&(A[j][i] == 'B'))
			{
				marked = true;
				A[j][i] = '.';
			}
			else if ((marked == true)&&((A[j][i] == '.')||(j == n-1)))
			{
				count++;
				marked = false;
			}
			else if ((marked == true)&&(A[j][i] == 'B'))
			{
				A[j][i] = '.';
			}
	
		}
	}	
/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j];
		cout << endl;
	}
*/
	cout << count << endl;
	
	return 0;
}
