#include <bits/stdc++.h>

using namespace std;
void recSol(vector<int> A, int source, int len, int &ans)
{
//	cout << "AA" << endl;
	ans++;
}

int main()
{
	int T, N = 0;
	vector<int> A(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> A[i];
		N+=A[i];
	}
//	unsigned long long int ans = 0;
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		A[i]--;
		recSol(A, i, N-1, ans);
		A[i]++;
	}
	cout << ans << endl;
	return 0;
}
