#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, N, w, c, d;
	cin >> T;
	w = T;
	while(T--)
	{
		cin >> N;
		int max_i = 0;
		vector<int> A(5002, 0);
		while(N--)
		{
			cin >> c;
			cin >> d;
			if (d < c)
			{
				int temp = c;
				c = d;
				d = temp;
			}
			if (d > 5000)
				d = 5000;
			if (d+1 > max_i)
				max_i = d+1;
			A[c]++;
			A[d+1]--;
		}
		for(int i = 1; i <= max_i; i++)
		{
			A[i] += A[i-1];
		}
		vector<int> F;
		cin >> N;
		while(N--)
		{
			cin >> c;
			if (c > max_i)
				F.push_back(A[max_i]);
			else
				F.push_back(A[c]);
		}
		cout << "Case #" << (w - T) << ": ";
		for (int i = 0; i < F.size(); i++)
		{
			cout << F[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
