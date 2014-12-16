#include <bits/stdc++.h>

using namespace std;

string A[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void recP(int l, int ind, string s, string t)
{
	if (ind == 0)
	{
		cout << t << " ";
		return;
	}
	char e = s[l-ind];
	int c = e-'0';
//	cout << c << endl;
	int f = A[c].length();
//	cout << f << endl;
	string h = t;
	for (int i = 0; i < f; i++)
	{
		t = h;
		t = t + A[c][i];
		recP(l, ind-1, s, t);
	}
}

int main()
{
	string s, t = "";
	cin >> s;
	int l = s.length();
	recP(l, l, s, t);
	return 0;
}
