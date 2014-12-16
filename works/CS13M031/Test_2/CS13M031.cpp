#include <bits/stdc++.h>

using namespace std;

int source, dest;
map<int, int> D;

int calMin(vector<vector<int> > W)
{
	int l = W[0].size()-2;
	vector<int> P(l);
	for (int i = 1; i <= l; i++)
		P[i-1] = i;
	int s = 0, min = INT_MAX, ini;
	do
	{
		s = 0;
		ini = 0;
		for (int i = 0; i < l; i++)
		{
			s+=W[ini][P[i]];
			ini = P[i];
		}
		s += W[ini][l+1];
		if (s < min)
			min = s;
	}
	while(next_permutation(P.begin(), P.end()));
	return min;
}




void BFS(vector<vector<int> > A, vector<bool>& V, vector<int>& W, int s, int dist)
{
	if (V[s] == false)
	{
		V[s] = true;
		if (D.count(s) == 1)
			W[D[s]] = dist;
	}
	else
		return;
	int l = A[s].size();
	int r = 0;
	while (r < l)
	{
		BFS(A, V, W, A[s][r], dist+1);
		r++;
	}
}

int main()
{
	int m, n, t = 0, t2 = 1;
	cin >> n;
	cin >> m;
	char c;
	vector<vector<int> > A;
	vector<vector<int> > B(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> c;
//			cout << c ;
			if (c == '#')
				B[i][j] = -1;
			else if (c == '.')
			{
				B[i][j] = t;
				t++;
			}
			else if (c == '@')
			{
				D[t] = t2;
				t2++;
				B[i][j] = t;
				t++;
			}
			else if (c == 'S')
			{
				D[t] = 0;
				B[i][j] = t;
				t++;
				source = t-1;
			}
			else
			{
				B[i][j] = t;
				t++;
				dest = t-1;
			}
		}
//		cout << endl;
	}
	D[dest] = t2;
//	cout << t << endl;
	vector<vector<int> > W(t2+1, vector<int>(t2+1, INT_MAX));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (B[i][j] != -1)
			{
				vector<int> E;
				A.push_back(E);
				if ((i-1 >= 0)&&(B[i-1][j] != -1))
				{
					A[B[i][j]].push_back(B[i-1][j]);
				}
				if ((i+1 < m)&&(B[i+1][j] != -1))
				{
					A[B[i][j]].push_back(B[i+1][j]);
				}
				if ((j-1 >= 0)&&(B[i][j-1] != -1))
				{
					A[B[i][j]].push_back(B[i][j-1]);
				}
				if ((j+1 < n)&&(B[i][j+1] != -1))
				{
					A[B[i][j]].push_back(B[i][j+1]);
				}
			}
		}
	}
/*	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << B[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;
*/
	for (map<int,int>::iterator it=D.begin(); it!=D.end(); ++it)
	{
		vector<bool> visited(t, false);
		BFS(A, visited, W[it->second], it->first, 0);
		if (it->second == 0)
			for (int i = 0; i <= t2; i++)
				if (!visited[i])
				{
					cout << "-1" << endl;
					return 0;
				}
	}
/*	for (int i = 0; i <= t2; i++)
	{
		for (int j = 0; j <= t2; j++)
		{
			cout << W[i][j] << "	";
		}
		cout << endl;
	}
*/
	int a = calMin(W);
	cout << a << endl;
	return 0;
}
