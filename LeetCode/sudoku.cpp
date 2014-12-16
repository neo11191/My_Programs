#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void wait ( int seconds ) 
{ 
  clock_t endwait; 
  endwait = clock () + seconds * CLOCKS_PER_SEC ; 
  while (clock() < endwait) {} 
}



void solveSudoku(vector<vector<char> > &board) {
        int m = 9, n = 9;
        vector<vector<string> > A(m, vector<string>(n,"111111111"));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != '.')
                {
                    for (int k = 0; k < 9; k++)
                    {
                        if (board[i][j] != k+1)
                            A[i][j][k] = '0';
                    }
                }
            }
        }
        string r = "111111111";
        for (int i = 0; i < 9; i++)
        {
            r = "111111111";
            int start_i = (i/3)*3;
            int start_j = (i%3)*3;
            for (int j = 0; j < 3; j++)
            {
                start_j = (i%3)*3;
                for (int k = 0; k < 3; k++)
                {
                    if (board[start_i][start_j] != '.')
                    {
                        int yy = board[start_i][start_j] - '0';
                        r[yy-1] = '0';
                    }
                    start_j++;
                }
                start_i++;
            }
         start_i = (i/3)*3;
         start_j = (i%3)*3;
     
            for (int j = 0; j < 3; j++)
            {
                start_j = (i%3)*3;
                for (int k = 0; k < 3; k++)
                {
                    if (board[start_i][start_j] == '.')
                    {
                        //modify A[j][k]
                        for (int e = 0; e < 9; e++)
                        {
                            if ((r[i] == '1')&&(A[start_i][start_j][e] == '1'))
                                A[start_i][start_j][e] = '1';
                            else
                                A[start_i][start_j][e] = '0';
                        }
                    }
                    start_j++;
                }
                start_i++;
            }
        }
	
            for (int i = 0; i < 9; i++)
            {
                r = "111111111";
                for (int j = 0; j < 9; j++)
                {
                    if (board[j][i] != '.')
                    {
                        int c = board[j][i]-'0';
                        r[c-1] = '0';
                    }
                }
                for (int j = 0; j < 9; j++)
                {
                    if (board[j][i] == '.')
                   {
                        for (int e = 0; e < 9; e++)
                        {
                            if ((r[e] == '1')&&(A[j][i][e] == '1'))
                                A[j][i][e] = '1';
                            else
                                A[j][i][e] = '0';
                        }
                    }
                }
	}

    for (int i = 0; i < 9; i++)
            {
                r = "111111111";
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] != '.')
                    {
                        int c = board[i][j]-'0';
                        r[c-1] = '0';
                    }
                }
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        for (int e = 0; e < 9; e++)
                        {
                            if ((r[e] == '1')&&(A[i][j][e] == '1'))
                                A[i][j][e] = '1';
                            else
                                A[i][j][e] = '0';
                        }
                    }
                }
	}
		

        int change = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    change++;
            }
        }
        while(change > 0)
        {
		cout << " iteration" << change <<  endl;


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << "	";
		cout << endl;
	}
	


		
		wait(1);
            for (int i = 0; i < 9; i++)
            {
                r = "111111111";
                for (int j = 0; j < 9; j++)
                {
                    if (board[j][i] != '.')
                    {
                        int c = board[j][i]-'0';
                        r[c-1] = '0';
                    }
                }
		vector<int> F(9, 0);
                for (int j = 0; j < 9; j++)
                {
                    if (board[j][i] == '.')
                   {
                        for (int e = 0; e < 9; e++)
                        {
                            if ((r[e] == '1')&&(A[j][i][e] == '1'))
                                A[j][i][e] = '1';
                            else
                                A[j][i][e] = '0';
                        }
			for (int e = 0; e < 9; e++)
			{
				if (A[j][i][e] == '1')
					F[e]++;
			}
                    }
                }
		for (int j = 0; j < 9; j++)
		{
			if (F[j] == 1)
			{
				for (int e = 0; e < 9; e++)
				{
					if ((board[e][i] == '.')&&(A[e][i][j] == '1'))
					{
						board[e][i] = '0'+(char)j+1;
						A[e][i] = "000000000";
						A[e][i][j] = '1';
						change--;
					}
				}
			}
		}

            }
            for (int i = 0; i < 9; i++)
            {
                r = "111111111";
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] != '.')
                    {
                        int c = board[i][j]-'0';
                        r[c-1] = '0';
                    }
                }
		vector<int> F(9,0);
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] == '.')
                    {
                        for (int e = 0; e < 9; e++)
                        {
                            if ((r[e] == '1')&&(A[i][j][e] == '1'))
                                A[i][j][e] = '1';
                            else
                                A[i][j][e] = '0';
                        }
			for (int e = 0; e < 9; e++)
			{
				if (A[i][j][e] == '1')
					F[e]++;
			}
                    }
                }
		for (int j = 0; j < 9; j++)
		{
			if (F[j] == 1)
			{
				for (int e = 0; e < 9; e++)
				{
					if ((board[i][e] == '.')&&(A[i][e][j] == '1'))
					{
						board[i][e] = '0'+(char)j+1;
						A[i][e] = "000000000";
						A[i][e][j] = '1';
						change--;
					}
				}
			}
		}
            }
	for (int i = 0; i < 9; i++)
            {
                r = "111111111";
                int start_i = (i/3)*3;
                int start_j = (i%3)*3;
                for (int j = 0; j < 3; j++)
                {
                    start_j = (i%3)*3;
                    for (int k = 0; k < 3; k++)
                    {
                        if (board[start_i][start_j] != '.')
                        {
                            int yy = board[start_i][start_j] - '0';
                            r[yy-1] = '0';
                        }
                        start_j++;
                    }
                    start_i++;
                }
               	start_i = (i/3)*3;
                start_j = (i%3)*3;
		vector<int> F(9, 0);
                for (int j = 0; j < 3; j++)
                {
                    start_j = (i%3)*3;
                    for (int k = 0; k < 3; k++)
                    {
                        if (board[start_i][start_j] == '.')
                        {
                            //modify A[j][k]
                            for (int e = 0; e < 9; e++)
                            {
                                if ((r[i] == '1')&&(A[start_i][start_j][e] == '1'))
                                    A[start_i][start_j][e] = '1';
                                else
                                    A[start_i][start_j][e] = '0';
                            }
				for (int e = 0; e < 9; e++)
				{
					if (A[start_i][start_j][e] == '1')
						F[e]++;
				}
                        }
                        start_j++;
                    }
                    start_i++;
                }
		for (int e = 0; e < 9; e++)
		{
			if (F[e] == 1)
			{

                start_i = (i/3)*3;
                start_j = (i%3)*3;
                for (int j = 0; j < 3; j++)
                {
                    start_j = (i%3)*3;
                    for (int k = 0; k < 3; k++)
                    {
                        if (board[start_i][start_j] == '.')
                        {
				if (A[start_i][start_j][e] == '1')
				{
					board[start_i][start_j] = '0'+(char)e+1;
					A[start_i][start_j] = "000000000";
					A[start_i][start_j][e] = '1';
					change--;
				}
                        }
                        start_j++;
                    }
                    start_i++;
                }
 


			}
		}
            }
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    int ee = 0, aa = 0;
                    if (board[i][j] == '.')
                    {
                        for (int e = 0; e < 9; e++)
                        {
                            if (A[i][j][e] == '1')
                            {
                                ee++;
                                aa = e+1;
                            }
                        }
                        if (ee == 1)
                        {
                            board[i][j] = '0'+ (char)aa;
				A[i][j] = "000000000";
				A[i][j][aa-1] = '1';
                            change--;
                        }
                    }
                }
            }

        }
    }

int main ()
{
	vector<vector<char> > board(9, vector<char>(9, '.'));
	char c;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}
	solveSudoku(board);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << "	";
		cout << endl;
	}
	return 0;
}
