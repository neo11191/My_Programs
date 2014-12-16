#include <bits/stdc++.h>

using namespace std;

int combi(int n, int c)
{
	int m = n;
	unsigned long long int f = 1;
	while (n > c)
	{
		f = f*n;
		n--;
	}
	c = m-c;
	while (c > 0)
	{
		f = f/c;
		c--;
	}
	return f;
}


void genPer(vector<bool>& A, int l, bool flag)
{
	int n = A.size();
	if (!flag)
	{
		for (int i = 0; i < l; i++)
		{
			A[i] = true;
		}
		for (int i = l; i < n; i++)
			A[i] = false;
	}
	else
	{
/*		int c = n;
		for (int i = n-1; i >= 0; i--)
		{
			if (A[i] == 1)
				A[i] = 0;
			else
			{
				c = i;
			}	
		}
		for (int i = c; i < n; i++)
		{
			A[i] = true;
		}
	}
*/
		prev_permutation(A.begin(), A.end());
	}
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> lL(n);
	vector<int> uL(n);
	int t = n;
	while (t--)
	{
		cin >> lL[n-1-t];
		cin >> uL[n-1-t];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (lL[i] < lL[j])
			{
				int t1 = lL[i];
				int t2 = uL[i];
				lL[i] = lL[j];
				uL[i] = uL[j];
				lL[j] = t1;
				uL[j] = t2;
			}
		}
	}
	int min = INT_MAX, count = 0;
	for (int i = n; i > 0; i--)
	{
		int c = 0, s = 0;
		bool flag = false, cflag = false;
		vector<bool> np(n, false);
		int l = combi(n,i);
		while (l--)
		{
			s = 0;
			c = 0;
			genPer(np, i, flag);
			flag = true;
			for (int j = 0; j < n; j++)
			{
				if (np[j])
				{
					s+=lL[j];
					c+=uL[j];
				}
			}
			if (c <= 9000)
				break;
			cout << c << ":" << s << " = " << min << " : " << count << endl;
			if (c < min)
			{
				min = c;
				if (s > 9000)
				{
					count = count + c-s+1;
					min = s;
				}
				else
				{
					count += c-9000;
				}
					
			}
			else if ((s < min)&&(s > 9000))
			{
				count += min - s;
				min = s;
			}
			else if (s < min)
			{
				count += min - 9000 - 1;
				min = 9001;
			}
			cflag = true;
		}
		if (cflag == false)
			break;
	}
	cout << count << endl;
	return 0;
} 
