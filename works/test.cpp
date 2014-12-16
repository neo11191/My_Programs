#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<int, int> A;
	for (int i = 0; i < 10; i++)
		A[i] = i+1;
	for (int i = 0; i < 11; i++)
		cout << A[i] << endl;
	return 0;
}
