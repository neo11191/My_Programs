#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, G, C, R, M;
	cin >> N;
	M = N;
	while(N--)
	{
		cin >> G;
		R = 0;
		while(G--)
		{
			cin >> C;
			R = R^C;
		}
		cout << "Case #"<< M-N << ": " << R << endl;
	}
	return 0;
}
