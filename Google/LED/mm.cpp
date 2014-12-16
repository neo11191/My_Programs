#include <bits/stdc++.h>

using namespace std;

bitset<7> A0(string("0111111"));
bitset<7> A1(string("0000110"));
bitset<7> A2(string("1011011"));
bitset<7> A3(string("1001111"));
bitset<7> A4(string("1100110"));
bitset<7> A5(string("1101101"));
bitset<7> A6(string("1111101"));
bitset<7> A7(string("0000111"));
bitset<7> A8(string("1111111"));
bitset<7> A9(string("1101111"));

void isValid(vector<bool>& A, queue<int>& B)
{	
	queue<int> C;
	if (B.empty())
		for(int i = 0; i < 10; i++)
		{
			bool u = false;
			switch(i)
			{
				case 0:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A0[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 1:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A1[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}	
				case 2:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A2[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 3:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A3[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 4:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A4[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 5:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A5[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 6:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A6[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 7:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A7[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 8:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A8[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(i);
						break;
					}
				case 9:
					{
						for (int j = 0; j < 7; j++ )
						{
							if ((A[j] != A9[j])&&(A[j] == 1))
							{
								u = true;
								break;
							}
						}
						if (u == false)
							B.push(9);
						break;
					}
			}
		}
	else
	{
		while (!B.empty())
		{
			int d = B.front();
//			cout << d << endl;
			B.pop();
			bool u = false;
			switch(d)
			{
				case 0:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A9[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(9);
					break;
				}
				case 1:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A0[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(0);
					break;
				}	
				case 2:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A1[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(1);
					break;
				}
				case 3:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A2[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(2);
					break;
				}
				case 4:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A3[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(3);
					break;
				}
				case 5:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A4[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(4);
					break;
				}
				case 6:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A5[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(5);
					break;
				}
				case 7:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A6[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(6);
					break;
				}
				case 8:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A7[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(7);
					break;
				}
				case 9:
				{
					for (int j = 0; j < 7; j++ )
					{
						if ((A[j] != A8[j])&&(A[j] == 1))
						{
							u = true;
							break;
						}
					}
					if (u == false)
						C.push(8);
					break;
				}
			}
		}
		while (!C.empty())
		{
			B.push(C.front());
			C.pop();
		}
	}
	return;
}

int main()
{
	int T;
	cin >> T;
//	for (int i = 0; i < 7; i++)
//	{
//		cout << A0[i];
//	}
	cout << endl;
	for (int i = 0; i < T; i++)
	{
		int N, result = -1;
		cin >> N;
		vector<vector<bool> > A(N, vector<bool>(7));
		queue<int> C;
		for (int j = 0; j < N; j++)
		{
			bitset<7> B;
			cin >> B;
			for (int k = 0; k < 7; k++)
			{
				A[j][k] = B[6-k];
			}
			if (result == -1)
			{
				isValid(A[j], C);
//				cout << j << "	" << B << "	" << C.size() << endl;
			}
			if(C.empty())
				result = 100;	
		}
		if (C.empty())
		{
			result = -1;
		}
		else if (C.size() > 1)
		{
			result = -1;
		}
		else
			result = C.front();
		bitset<7> D;
		if (result != -1)
		{
			switch(result)
			{
				case 0:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A9[y];
					}
					break;
				}								
				case 1:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A0[y];
					}
					break;
				}
				case 2:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A1[y];
					}
					break;
				}
				case 3:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A2[y];
					}
					break;
				}
				case 4:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A3[y];
					}
					break;
				}
				case 5:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A4[y];
					}
					break;
				}
				case 6:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A5[y];
					}
					break;
				}
				case 7:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A6[y];
					}
					break;
				}
				case 8:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A7[y];
					}
					break;
				}
				case 9:
				{
					for (int y = 0; y < 7; y++)
					{
						D[y] = A8[y];
					}
					break;
				}

			}		
			cout << "Case #" << i+1 << ": ";
			for (int y = 0; y < 7; y++ )

			{
				bool e = 1;
				for (int t = 0; t < N; t++)
				{
					e = e & ~A[t][y];
				}
				if (e == 1)
					D[y] = 0;
				cout << D[y];
			}
			cout << endl;
		}
		else	
			cout << "Case #" << i+1 << ": ERROR!" << endl;
		
	}
	return 0;
}
