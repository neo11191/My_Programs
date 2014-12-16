#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<float> vf;

int main()
{
	int T, n;
	float m;
	scanf("%d", &T);
	while(T--)
	{
		char c;
		c = getchar();
		cout << c << endl;
		c = getchar();
		cout << c << endl;
		vi A;
		int g;
		while(c != '\0')
		{
			g = 0;
			while((c != ' '),(c != '\0'))
			{
				g = g*10 + c - '0';
				c = getchar();
				cout << g << "	";
			}
			cout << endl;
			if (c == ' ')
				c = getchar();
			A.push_back(g);
		}
		cout << "**************************" << endl;
		vf B(A.size());
		for (int i = 0; i < A.size(); i++)
		{
			cin >> B[A[i]];
		}
		
		for (int i = 0; i < A.size(); i++)
		{
			cout << B[i] << endl;
		}
		printf("\n");
	}
	return 0;
}
