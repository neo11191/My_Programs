#include <bits/stdc++.h>

using namespace std;

bool opp(pair<int,int> A, pair<int,int> B)
{
	return (A.first > B.first)||((A.first == B.first)&&(A.second < B.second ));
}

int main()
{
	int n;
	cin >> n;
//	set<pair<int,int> > A(opp(pair<int,int> a, pair<int,int> b));
	set<pair<int,int>, bool (*)(pair<int, int>, pair<int, int>) > A(opp);
	while(n--)
	{
		pair<int, int> B;
		cin >> B.first;
		cin >> B.second;
		A.insert(B);
	}
	for (set<pair<int,int> >::iterator it = A.begin(); it != A.end(); it++)
	{
		cout << it->first << "	" << it->second << endl;
	}
	return 0;
}
