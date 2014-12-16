#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;
typedef vector<pair<int,int> > vii;
typedef map<int,int> mi;
typedef pair<int,int> pi;
typedef map<int, pair<int, int> > mip;
typedef pair<int,int> pii;
typedef queue<int> qi;
/*
int findMin(mi& A, vector<queue<int> >& B, vector<int>& D){
    int M = B.size();
//    map<int, int> E;
    vector<bool> C(1001, true);
    int min_count = 10000, min_val = 10000;
    for (int i = 0; i < M; i++){
        if (D.count(B[i].front()) != 1){
            D[B[i].front()] = 1;
//            E[B[i].front()] = i;
        }
        else
            D[B[i].front()]++;
    }
    for (map<int, int>::iterator it = D.begin(); it != D.end(); it++){
        if ((it->first < min_val)&&(it->second == A[it->first]))
            min_val = it->first;
    }
    return min_val;
}
*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    mip A;
    int M, N, v;
    cin >> M;
    vector<queue<int> > B(M, queue<int>());
    int q_no = 0;
    while(M--){
        cin >> N;
        int pos = 1;
        while(N--){
            cin >> v;
            if (A.count(v) != 1){
                pi W;
                W.first = 1;
                W.second = 0;
                A[v] = W;
            }
            else 
                A[v].first++;
            B[q_no].push(v);
        }
        B[q_no].push(INT_MAX);
        q_no++;
    }
    A[INT_MAX].first = INT_MAX;
    A[INT_MAX].second = 0;
    int t1, t2, count1;
    set<int> D;
    for (int i = 0; i < B.size(); i++){
        t1 = B[i].front();
        A[t1].second++;
        if (A[t1].first == A[t1].second){
            D.insert(t1);
        }
    }
    int k = 0;
    while(!D.empty()){
        t1 = *D.begin();
        D.erase(D.begin());
        if (k == 0){
            cout << t1;
            k++;
        }    
        else
            cout << " " << t1;
        count1 = A[t1].first;
        for (int i = 0; ((i < B.size())&&(count1 > 0)); i++){
            if (B[i].front() == t1){
                B[i].pop();
                t2 = B[i].front();
                A[t2].second++;
                if (A[t2].first == A[t2].second){
                    D.insert(t2);
                }
                count1--;
            }
        }
        
    }
    return 0;
}
