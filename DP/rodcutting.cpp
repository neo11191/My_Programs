#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	m = 1;
	vector<int> P(n+1);
	P[0] = 0;
	vector<int> profit(n);
	profit[0] = 0;
	while(m < n+1)
	{
		cin >> P[m];
		profit[m] = P[m];
		m++;
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= ceil(i/2); j++)
		{
			profit[i] =  profit[i] >= (profit[j]+profit[i-j]) ? profit[i] : (profit[j]+profit[i-j]);
		}
	}
	cout << profit[n] << endl;
	return 0;
}
