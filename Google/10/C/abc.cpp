#include <bits/stdc++.h>

using namespace std;


void printFun(vector<vector<bool> >& A, int s, map<string, int>& M, int m)
{
	 map<string, int>::iterator it1 = M.begin();
	while(it1->second != s)
		it1++;
	for (int i = 0 ; i < m; i++)
	{
		if (A[s][i])
		{
			map<string, int>::iterator it2 = M.begin();
			while(it2->second != i)
				it2++;
	
			cout << it1->first << "-" << it2->first << " ";
			printFun(A, i, M, m);
		}
	}
}

int main()
{
	int T, N, w;
	cin >> T;
	w = T;
	while(T--)
	{
		cin >> N;
		int m = N + 1;
		int count = 0;
		string a,b;
		int source, dest;
//		vector<string> S;
		map<string, int> M;
		vector<vector<bool> > A(m, vector<bool>(m, 0));
		while(N--)
		{
			cin >> a;
			cin >> b;
			map<string, int>::iterator it1 = M.find(a);
			if (it1 == M.end())
			{
//				S.push_back(a);
				M[a] = count;
				source = count;
				count++;
			}
			else
			{
				source = it1->second;
			}
			map<string, int>::iterator it2 = M.find(b);
			if (it2 == M.end())
			{
//				S.push_back(b);
				M[b] = count;
				dest = count;
				count++;
			}
			else
				dest = it2->second;
//			cout << source << ":" << dest << "=" << count << endl;
			A[source][dest] = true;
		}
		for (int i = 0; i < m; i++)
		{
			int r1 =0, c1 = 0;
			for (int j = 0; j < m; j++)
			{
				if (A[j][i])
					c1++;
			}
			if (c1 == 0)
			{ 
				source = i;
				break;
			}
		}
/*		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
*/		int c1 = m, c2 = m;
		cout << "Case #" << (w - T) << ": ";
		printFun(A, source, M, m);
		cout << endl;
	}
	return 0;
}
