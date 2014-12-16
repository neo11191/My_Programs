#include <bits/stdc++.h>

using namespace std;

bitset<10> R;
int numD(int M)
{
	int num_digits = 0;
	while (M > 0)
	{
		num_digits++;
		M = M/10;
	}
	return num_digits;
}
int valid(int M)
{
	int num_digits = 0;
	while (M > 0)
	{
		int g = M % 10;
		if (R[g] == 1)
			num_digits++;
		M = M/10;
	}
	return num_digits;
}			
int factorMin(int N, int min)
{
	int temp_min, s, d, k = 0, d1,s1;
	if (((N == 1)||(N==2)||(N==3)||(N==5)||(N==7))&&(valid(N) == 0))
		return min;
	for (int i = 2; i <= sqrt(N); i++)
	{
		temp_min = 0;
		k = 0;
		s = 0;
		d = 0;
		d1 = 0;
		s1 = 0;
		if (N % i == 0)
		{
			s+= numD(i);
			d+= valid(i);
			if (s == d)
			{
				temp_min+=d;  
				k++;
			}
			d1+= valid(N/i);
			s1+= numD(N/i); 
			if (s1 == d1)
			{
				temp_min+=d1;
				k= k+2;
			}
			s+=s1;
			d+=d1;
			if (s >= min)
				continue;
			if ((k == 3)&&((temp_min+1) < min))
			{
				min = temp_min+1;
			}
			else
			{
				int y1, y2;
				if ( k == 0)
				{
					y1 = factorMin(i, min);
					y2 = factorMin(N/i, min);
					if ((y1 == INT_MAX)||(y2 == INT_MAX))
						continue;
					if ((y1 + y2 + 1) < min)
						min = y1 + y2 + 1;
				}
				else if (k == 1)
				{			
					y2 = factorMin(N/i, min);
					
					if ((y2 != INT_MAX)&&((temp_min+y2+1)<min))
						min = temp_min + y2 + 1;
				}
				else if (k == 2)
				{
					y1 = factorMin(i, min);
					if ((y1 != INT_MAX)&&((temp_min+y1+1)<min))
						min = temp_min + y1 + 1;
				
				}
			}
		}
	}
	return min;
}
			
	



int main()
{
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++)
	{
		int N;
		int count = 0;
		for (int i = 0; i < 10; i++)
		{
			bool M;
			cin >> M;
			R[i] = M;
			if (M == 1)
				count++;
		}
		cin >> N;
		if ( N < 0)
			cout << "Case #" << x << ": Impossible" << endl;
		int M = N;
		int num_digits = 0, ex = 0;
		num_digits = numD(M);
		ex = valid(M);
		if (num_digits == ex)
		{
			ex++;
			cout << "Case #" << x << ": " << ex << endl;
		}
		else
		{
			//find factors
			//put in a list
			//count total digits
			//update min
/*			int min = INT_MAX, s, d;
			for (int i = 2; i < sqrt(N)+1; i++)
			{
				s = 0;
				d = 0;
				if (N % i == 0)
				{
					s+= numD(i);
					s+= numD(N/i); 
					d+= valid(i);
					d+= valid(N/i);
					
					if ((d == s)&&(s < min))
					{
						min = s;
						cout << i << " : " << N/i << endl;
					}
					else if (s < min)
					{
						int h = 0,y = 0;
						while ()
					}
				
				}
			}
*/
			int min = INT_MAX;
			min = factorMin(N, min);
			if (min == INT_MAX)
				cout << "Case #" << x << ": Impossible" << endl;
			else
				cout << "Case #" << x << ": " << min+1 << endl;
		}
	}
}
