#include <bits/stdc++.h>

using namespace std;

int main()
{
/*	set<pair<int, int>, greater<pair<int, int>> > A;
	A.insert(1, 2);
	A.insert(1, 3);
	A.insert(1, 1);
	A.insert(4, 1);
	A.insert(5, 1);
	A.insert(7, 1);
	for (set<int>::iterator it = A.begin(); it != A.end(); it++)
		cout << it->first << " , " << it->second << endl;;
*/

	pair<int, int> A;
	A[0].first = 3;
	A[0].second = 2;
	A[1].first = 5;
	A[1].second = 4;
	
	cout << A[0].first << ":" << A[1].second << endl;
	return 0;
}
