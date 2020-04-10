#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;


//----------Struct-------------

struct UnionFind{
    vector<int> parent;

    UnionFind(int N): parent(N){
        loop(i, N) parent[i] = i;
    }

    int root(int x){
        if(parent[x] == x)return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        parent[rx]= ry;
        return;
    }

    bool same(int x,int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};