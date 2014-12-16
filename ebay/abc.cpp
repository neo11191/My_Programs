#include <bits/stdc++.h>

using namespace std;

bool fpp(pair<int, int> A, pair<int, int> B)
{
	return (A.first > B.first)||((A.first == B.first)&&(A.second < B.second));
}

void prints(string& s)
{
	int l = s.size();
	int min = 0, h = 1, m = 0;
	vector<int> A;
	while(h < l)
	{
		A.push_back(m);
		if (s[h] > s[h-1])
			m++;
		else if (s[h] < s[h-1])
			m--;
		h++;
		if (m < min)
			min = m;
	}
	A.push_back(m);
	if (min < 0)
		min = min * -1;
	else
		min = 0;
	h = 0;
	m = 0;
	int max = 0;
	set<pair<int, int>, bool (*)(pair<int, int>, pair<int, int>) > B(fpp);
	while (h < l)
	{
		pair<int, int> b;
		if (A[h]+min > max)
			max = A[h]+min;
		b.first = A[h]+min;
		b.second = h;
		B.insert(b);
		h++;
	}
	int prev_lvl = max, prev_ind = 0;
	for (set<pair<int, int> >::iterator it = B.begin(); it != B.end(); it++ )
	{
//		cout << it->first << "::" << it->second << endl;
		if (prev_lvl == it->first)
		{
			while(it->second > prev_ind)
			{
				cout << "_";
				prev_ind++;
			}
			cout << s[it->second];
			prev_ind++;
		}
		else
		{
			prev_lvl = it->first;
			prev_ind = 0;
			cout << endl;
			while(it->second > prev_ind)
			{
				cout << "_";
				prev_ind++;
			}
			cout << s[it->second];
			prev_ind++;
	
		}

	}	
	cout << endl;
}

int main()
{
	string s;
	cin >> s;
	prints(s);
	return 0;
}
