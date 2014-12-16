#include <bits/stdc++.h>

using namespace std;

    int evalRPN(vector<string> &tokens) {

        stack<int> A;

        if (((tokens.size()-1) % 2 != 0)||(tokens.size() < 1))
	{
		cout << tokens.size() << endl;
		cout << "zzz" << endl;
            return 0;
	}
        for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)

        {

            if ((*it != "+")&&(*it != "-")&&(*it != "*")&&(*it != "/"))

            {

                int n = 0;

                string s = *it;

                int l = s.size(), a = 0;

                if (s[0] == '-')

                    a++;

                for (int i = a; i < l; i++)

                {

                    n= n*10+(s[i]-'0');

                }
	
                if (a == 0)

                    A.push(n);

                else

                {

                    n = -1 * n;

                    A.push(n);

                }
		cout << n << endl;
            }

            else

            {

                if (A.empty())

                    return 0;

                int a = A.top();

                A.pop();

                if (A.empty())

                    return a;

                int b = A.top();

                A.pop();

                if (*it == "+")

                {

                    A.push(a+b);

                }

                else if (*it == "-")

                {

                    A.push(a-b);

                }

                else if (*it == "*")

                {

                    A.push(a*b);

                }

                else if (*it == "/")

                {

                    if (b != 0)

                        A.push(a/b);

                }

            }

            

        }

        return A.top();

    }


int main()
{
	vector<string> A;
	A.push_back("3");
	A.push_back("-4");
	A.push_back("+");
    	cout << evalRPN(A) << endl;


	return 0;
}
