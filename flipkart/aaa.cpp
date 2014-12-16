#include <bits/stdc++.h>

using namespace std;

bool haha(int a, int b)
{
	return a>b;
}

int main()
{
	vector<int> A(25);
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
