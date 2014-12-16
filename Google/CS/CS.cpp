#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, C, I, J, l;
	cin >> N;
	M = N;
	while(N--)
	{
		cin >> C;
		cin >> I;
		J = I;
		map<int, int> A;
		while(J--)
		{
			cin >> l;
			A[l] = I-J-1;
		}
		
		cout << "Case #" << M-N << ": " << endl;
	}
	return 0;
}
