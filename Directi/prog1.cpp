#include <bits/stdc++.h>
#define MAX_SIZE 10000000

using namespace std;


int main()
{
	int T, N, a, b;
	cin >> T;
	while(T--)
	{
		cin >> N;
		vector<bool> A(MAX_SIZE+1,false);
		map<int, bool> B;
		set<int> C;
		while (N--)
		{
			cin >> a;
			if (a <= 0)
				a = 1;
			if (C.count(a) == 1)
			{
				B[a] = !B[a];
			}
			else
			{
				C.insert(a);
				B[a] = true;
			}
			cin >> b;
			if (b >= MAX_SIZE)
				b = MAX_SIZE;
			if (C.count(b) == 1)
			{
				B[b] = !B[b];
			}
			else
			{
				C.insert(b);
				B[b] = true;
			}
		}
		
		set<int>::iterator it2 = C.begin();
		while(it2 != C.end())
		{
			while((it2 != C.end())&&(!B[*it2]))
				it2++;
			if (it2 == C.end())
				continue;
			int begin = *it2, end1;
			it2++;
			while((it2 != C.end())&&(!B[*it2]))
				it2++;
			if (it2 == C.end())
				end1 = MAX_SIZE+1;
			else
				end1 = *it2;
			for (int i = begin; i < end1; i++)
			{
				A[i] = true;
			}
			it2++;
		}
		int d;
		vector<int> R(16, 0);
		for (int i = 1; i < MAX_SIZE; i = i+4)
		{
			d = 0;
			for (int j = 4; j >= 0; j-- )
			{
				if (A[i+j])
					d += pow(2,j-1);	
			}
			R[d]++;
		}
		for (int i = 0; i < 16; i++)
			cout << R[i] << " ";
		cout << endl;
	}
	return 0;
}
