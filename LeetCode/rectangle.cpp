#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1;
	vector<int> A(6);
	int temp = 0, num = 0, count = 0;
	for (int i = 0; i < 3; i++)
	{
		getline(cin, s1);
		stringstream s(s1);
		while (s>>temp)
		{
			num = num*10 + temp;
			if (s.peek() == ',')
			{
				s.ignore();
				A[count] = num;
				num = 0;
				count++;
			}
		}
		A[count] = num;
		num = 0;
		count++;
	}
	if (A[2] < A[4])
	{
		int t1 = A[4];
		int t2 = A[5];
		A[4] = A[2];
		A[5] = A[3];
		A[2] = t1;
		A[3] = t2;
	}
	int best = 0, worst = 0;
	if (A[5] >= A[2])
		best = A[0];
	else
	{
		int x = abs(A[2] - A[5]);
		if (x > abs(A[4]-A[2]))
			x =  abs(A[4]-A[2]);
		if (x > abs(A[5]-A[2]))
			x =  abs(A[5]-A[2]);
		if (x > abs(A[5]-A[3]))
			x =  abs(A[5]-A[3]);
		
		best = A[0]*A[0] + x*x;
		best = sqrt(best);
	}
	int max = 0;
	max = abs(A[4] - A[3]);
	if (max < abs(A[4]-A[2]))
		max =  abs(A[4]-A[2]);
	if (max < abs(A[5]-A[2]))
		max =  abs(A[5]-A[2]);
	if (max < abs(A[5]-A[3]))
		max =  abs(A[5]-A[3]);
	worst = A[1]*A[1] + max*max;
	worst = sqrt(worst);
	cout << best << "," << worst << endl;	
	return 0;
}
