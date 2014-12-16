#include <bits/stdc++.h>

using namespace std;

int main()
{
	int j = 1<<5;
	j += 12;
	j ^= (j & -j);
//	j |= j+1;
	j |= ((j & -j)-1);
	cout << j << endl;
	return 0;
}
