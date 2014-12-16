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
		cout << "Case #" << (w - T) << ": " << N << endl;
	}
	return 0;
}
