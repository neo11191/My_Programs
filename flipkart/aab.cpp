#include <bits/stdc++.h>

using namespace std;

bool haha(int a, int b)
{
	return a>b;
}

int main()
{
	vector<pair<int, int> > A(5);
	
	for (int i = 0; i < 5; i++)
	{
		pair<int, int> c;
		c.first = 2*i;
		c.second = i+1;
		A[i] = c;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << A[i].first << ":" << A[i].second << endl;
	}
	A[2].swap(A[3]);
	for (int i = 0; i < 5; i++)
	{
		cout << A[i].first << ":" << A[i].second << endl;
	}
	return 0;
}
/*	vector<int> A(25);
	for (int i = 0 ;i < 25; i++)
	{
		A[i] = i;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < 25; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	sort(A.rbegin(), A.rend());
	for (int i = 0; i < 25; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	sort(A.begin(), A.end());
	for (int i = 0; i < 25; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	sort(A.begin(), A.end(), haha);
	for (int i = 0; i < 25; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	
	
}
*/
