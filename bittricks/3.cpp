#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<float> vf;

int main()
{
	int T;
	char c;
	scanf("%d", &T);
	while(T--)
	{
		getchar();
		printf("%d\n", T);
		vi A;
		int g;
//		c = getchar();
		scanf("%c", &c);
		while ((c != '\b')&&(c != EOF))
		{
			printf("%c\n", c);
//			c = getchar();
			scanf("%c", &c);
		}
/*		while ((c != '\0')&&(c != EOF))
		{	
			g = 0;
			while ((c != ' ')&&(c != '\0'))
			{
				g *= 10;
				g += c-'0';
				scanf("%c", &c);
			}
			if (c == ' ')
				scanf("%c", &c);
			printf("%d", g);
			A.push_back(g);
		}
		float ff;
		vf B(A.size());
		for (int i = 0; i < A.size(); i++)
		{
			scanf("%E", &ff);
			B[A[i]] = ff;
		}
		for (int i = 0 ; i < A.size(); i++)
		{
			printf("%E\n", B[i]);
		}
		printf("\n");
*/
	}
	return 0;
}
