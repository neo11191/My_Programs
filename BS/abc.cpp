#include <bits/stdc++.h>
using namespace std;



int main()
{
	int N = 0, M = 0, col = 0, h = 0;
	string S;
	cin >> S;
	while (h < S.length()-1)
	{
		N = N*10 + S[h]-'0';
		h++;
	}
	S = "";
	cin >> S;
	h = 0;
	while (h < S.length())
	{
		M = M*10 + S[h]-'0';
		h++;
	}
	cin >> S;
//	cout << N << " " << M << " " << S;
	vector<string> att(1, "");
	int l = S.length();
	h = 0;
	while(h < l)
	{
		if (S[h] == ',')
		{
			col++;
			att.push_back("");
		}
		else
		{
			if (S[h] != '"')
				att[col] += S[h];
		}
		h++;
	}
	map<string, int> Label;
	for (int i = 0; i <= col; i++ )
	{
		Label[att[i]] = i;
	}
	vector<vector<string> > Data(N+1, vector<string>(col+1));
	S = "";
	h = 0;
	int col2 = 0, h1;
	char c[1000000];
	cin.getline(c, 1000000);
		
	while(h < N)
	{
		char c[1000000];
		cin.getline(c, 1000000);
		h1 = 0;
		col2 = 0;
		while (c[h1] != '\0')
		{
			S = "";
			while((c[h1] != ',')&&(c[h1] != '\0'))
			{
				if (c[h1] != '"')
					S += c[h1];
				h1++;
			}
			Data[h][col2] = S;
			col2++;
			if (c[h1] != '\0')
				h1++;
		}
/*		
		while (c != '\0')
		{
			S = S + c;
			scanf("%c", &c);
		}
*/
//		cout << c << endl;

/*		while (c != '\0')
		{
			S = "";
			while((c != ',')&&(c != '\0'))
			{
				if (c != '"')
					S += c;
				cin >> c;
			}
			Data[h][col2] = S;
			col2++;
			if (c != '\0')
				cin >> c;
		}
*/
/*		for (int i = 0; i < col+1 ; i++)
			cout  << Data[h][i] << "	";
		cout << endl;
*/
		h++;
	}
//	cout << "READING DONE" << endl;
	while (M--)
	{
		char c[1000000];
		cin.getline(c, 1000000);
		S = "";
		h1 = 0;
		while ((c[h1] != ' ')&&(c[h1] != '<'))
		{
			S = S+c[h1];
			h1++;
		}
		h1++;
		bool flag = false;
		if (c[h1] == '=')
			flag = true;
		h1++;
		h1++;
		int ind = 0;
		if (Label.count(S) == 1)
		{
//			cout << S << "label is " << Label[S] << endl;
			ind = Label[S];
		}
//		else
//			cout << "NOT FOUND" << endl;
		S = "";
		while (c[h1] != '\0')
		{
			if (c[h1] != '"')
				S += c[h1];
			h1++;
		}
		int result = 0;
		if (flag)
		{
			for (int i = 0 ; i < N ; i++)
			{
				int kk = 0;
//				cout << S << " $$ " << Data[i][ind] << endl;
				while ((kk < S.length())&&(S[kk] == Data[i][ind][kk]))
				{
					if (kk == S.length()-1)
						result++;
					kk++;
				}
			}
		}
		else
		{
			for (int i = 0 ; i < N ; i++)
			{
				int kk = 0;
//				cout << S << " $$ " << Data[i][ind] << endl;
				while ((kk < S.length())&&(S[kk] == Data[i][ind][kk]))
				{
					kk++;
				}
				if ((kk != S.length())&&(S[kk] < Data[i][ind][kk]))
				{
//					cout << S << " $$ " << Data[i][ind] << endl;
					result++;
				}
			}
		
		}
		cout << result << endl;
/*	cout << "col is" << col << endl;
	
	for (int i = 0; i <= col; i++ )
	{
		cout << att[i] << endl;
	}
*/
	}
	return 0;
}

