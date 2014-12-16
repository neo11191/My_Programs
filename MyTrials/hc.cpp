#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef unsigned long long int ull;
typedef long long int lli;
typedef vector<pair<unsigned int, unsigned int> > vii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef queue<int> qi;
int source;
vector<int> height(50001, 0);


void modify(vi& edg, int endn, int startn, vi& match, int c){
    int h1 = height[startn];
//    cout << startn << "::" << h1 <<endl;
    int h2 = height[endn];
//    cout << endn << "::" << h2 <<endl;
    int cur1 = startn, cur2 = endn;
    if (h1 > h2){
        while (h1 != h2){
            match[cur1] = c;
            cur1 = edg[cur1];
            h1--;
        }
    }
    else{
        while (h1 != h2){
            match[cur2] = c;
            cur2 = edg[cur2];
            h2--;
        }
    }
    while (cur1 != cur2){
        match[cur1] = c;
        match[cur2] = c;
        cur1 = edg[cur1];
        cur2 = edg[cur2];
    }
    match[cur1] = c;
    return;
}

int LCA(vi& edg, int u, int v){
    int h1 = height[u];
//    cout << "LCA" << u << "::" << h1 <<endl;
    int h2 = height[v];
//    cout << "LCA" << v << "::" << h2 <<endl;
    int cur1 = u, cur2 = v;
    if (h1 > h2){
        while (h1 != h2){
            cur1 = edg[cur1];
            h1--;
        }
    }
    else{
        while (h1 != h2){
            cur2 = edg[cur2];
            h2--;
        }
    }
    while (cur1 != cur2){
        cur1 = edg[cur1];
        cur2 = edg[cur2];
    }
//    cout << cur1 << endl;
    return cur1;
}

int eval(vii& eqn, vi& edg, vi& match, int endn, int startn, int val){
    int cur = startn, a, b;
    stack<int> A;
        lli V = val;
    
    int lca =  LCA(edg, endn, startn);
    
    while (cur != lca){
        A.push(match[cur]);
        cur = edg[cur];
    }
    A.push(match[lca]);
    cur = endn;
    while (cur != lca){
        V = (eqn[match[cur]].first*V+eqn[match[cur]].second)%1000000007;
        cur = edg[cur];
    }
    
    while (!A.empty()){
        V = (eqn[A.top()].first*V+eqn[A.top()].second)%1000000007;
        A.pop();
    }
    val = V % 1000000007;
    return val;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, c1 = 1, a, b, c, t = 0;
    cin >> N;
    vii eqn(N+1, pair<int,int>());
    vi match(N+1);
    for (int i = 0; i < N+1; i++){
        match[i] = i;
    }
    while(c1 <= N){
        cin >> a;
        cin >> b;
        eqn[c1].first = a;
        eqn[c1].second = b;
        c1++;
    }
    vi edg(N+1, 0);
    c1 = 1;
    vector<vector<int> > adj(N+1, vector<int>());
    while (c1 < N){
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
//        edg[b] = a;
//        height[b] = height[a]+1;
        c1++;
    }
    source = 1;
    for (int i = 1; i <= N; i++){
        if (adj[i].size() > adj[source].size())
            source = i;
    }
    int nn = 0, cur = source;
    edg[cur] = 0;
    height[cur] = 0;
    vector<bool> lu(N+1, false);
    lu[source] = true;
    queue<int> qea;
    qea.push(source);
    while (!qea.empty()){
        cur = qea.front();
        qea.pop();
        for (int i = 0; i < adj[cur].size(); i++){
            if (!lu[adj[cur][i]]){
                height[adj[cur][i]] = height[cur]+1;
                edg[adj[cur][i]] = cur;
                qea.push(adj[cur][i]);
                lu[adj[cur][i]] = true;
            }
        }
    }
    c = N;
    int M, u, v;
    cin >> M;
    while(M--){
        cin >> a;
        if (a == 1){
            cin >> u;
            cin >> v;
            pii E;
            cin >> E.first;
            cin >> E.second;
            eqn.push_back(E);
            c++;
            modify(edg, u, v, match, c);
        }
        else{
            cin >> u;
            cin >> v;
            cin >> b;
            cout << eval(eqn, edg, match, u, v, b) << endl;
        }
    }
    return 0;
}
