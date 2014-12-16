#include <bits/stdc++.h>
using namespace std;
    int maxProduct2(int A[], int start, int n) {
        int neg_c = 0, prod = 1;
        if (n-1 == start)
            return A[start];
//        vector<int> zero_i();
//        vector<int> neg_i();
        for (int i = start; i < n; i++)
        {
/*            if (A[i] == 0)
            {
//                zero_c++;
                zero_i.push_back(i);
            }
            */
            if (A[i] < 0)
            {
                neg_c++;
//                neg_i.push_back(i);
            }
        }
//        if (zero_i.size() == 0)
//        {
            if (neg_c % 2 == 0)
                for (int i = start; i < n; i++)
                {
                    prod = prod * A[i];
                }
            else
            {
                int f_n = -1, l_n = -1, p1 = 1, p2 =1 ;
                for (int i = start; i < n; i++)
                {
                    if ((A[i] < 0)&&(f_n == -1))
                        f_n = i;
                    if ((A[n-1-i+start] < 0)&&(l_n == -1))
                        l_n = n-1-i+start;
                }
                if (f_n == l_n)
                {
                    if (start == n-1)
                        return A[start];
                    if (start == f_n)
                    {
                        for (int i = start+1; i < n; i++)
                            prod = prod * A[i];
                    }
                    else if (n-1 == f_n)
                    {
                        for (int i = start; i < n-1; i++)
                            prod = prod * A[i];
                    }
                    else
                    {
                        for (int i = start; i < f_n; i++)
                        {
                            p1 = p1 * A[i];
                        }                  
                        for (int i = f_n+1; i < n; i++)
                            p2 = p2 * A[i];
                        
                        if (p1 >= p2)
                            prod = p1;
                        else
                            prod = p2;
                    }
                }
                else
                {
			cout << "***" << start << " : " << f_n << " : " << l_n << " : " << n << endl;
                    int prod1 = 1, prod2 = 1;
                    for (int i = start; i < l_n; i++)
                        prod1 = prod1 * A[i];
                    for (int i = f_n+1; i < n; i++)
                        prod2 = prod2 * A[i];
                    if ( prod1 >= prod2)
                        prod = prod1;
                    else
                        prod = prod2;
                }
            }
            return prod;
//        }
    }
    
    
    int maxProduct(int A[], int n) {
        int neg_c = 0, prod = 0, z = 0;
        vector<int> zero_i;
//        vector<int> neg_i();
        if (n == 1)
            return A[0];
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 0)
            {
//                zero_c++;
                z++;
                zero_i.push_back(i);
            }
/*            if (A[i] < 0)
            {
                neg_c++;
//                neg_i.push_back(i);
            }
            */
        }
        if (z == 0)
        {
            /*
            if (neg_c % 2 == 0)
                for (int i = 0; i < n; i++)
                {
                    prod = prod * A[i];
                }
            else
            {
                
                int f_n = 0, l_n = 0;
                for (int i = 0; i < n; i++)
                {
                    if ((A[i] < 0)&&(f_n == 0))
                        f_n = i;
                    if ((A[n-1-i] < 0)&&(l_n == 0))
                        l_n = n-1-i;
                }
                int prod1 = 1, prod2 = 1;
                for (int i = 0; i < l_n; i++)
                    prod1 = prod1 * A[i];
                for (int i = f_n+1; i < n; i++)
                    prod2 = prod2 * A[i];
                if ( prod1 >= prod2)
                    prod = prod1;
                else
                    prod = prod2;
            
                prod = maxProduct2(A, 0, n);
            }
//            return prod;
    */
            prod = maxProduct2(A, 0, n);
        }
        else
        {
            int f = 0, p;
            for (int i = 0; i < zero_i.size(); i++)
            {
                if (f == 0)
                {
                    p = maxProduct2(A, 0, zero_i[i]);
                    if (p >= prod)
                        prod = p;
                    f++;
                }
                else
                {
                    p = maxProduct2(A, zero_i[i-1]+1, zero_i[i]);
                    if (p >= prod)
                        prod = p;
                }
            }
            if (zero_i[zero_i.size()-1] != n-1)
            {
                p = maxProduct2(A, zero_i[zero_i.size()-1]+1, n);
                    if (p >= prod)
                        prod = p;
            }
        }
        return prod;
        
    }


int main()
{
	int A[4] = {-1, -2, -3, 0};
	for (int i = 0; i < 4; i++)
		cout << A[i] << endl;
	cout << "Product is :" << maxProduct(A, 4) << endl;
	return 0;
}
