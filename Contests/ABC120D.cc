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

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct UnionFind{
    vector<int> parent;

    UnionFind(int N): parent(N,-1){
    }

    int root(int x){
        if(parent[x] < 0) return x;
        else {
            parent[x] = root(parent[x]);
            return parent[x];
        }
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;

        parent[rx] += parent[ry];
        parent[ry] = rx;

        return;
    }

    int size(int x){
        return -1 * parent[root(x)];
    }

    bool same(int x,int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    } 
};

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> a(m),b(m);
    loop(i,m) cin >> a[i] >> b[i];

    UnionFind tree(n);

    vector<ll> result(m);

    result[m-1] = ll(n) * ll((n-1)) /2;
    loop(i,m-1){
        int tmpA = a[m-1-i] - 1;
        int tmpB = b[m-1-i] - 1;

        if(tree.same(tmpA,tmpB)){
            result[m-2-i] = result[m-1-i];
        }else{
            ll asize = tree.size(tmpA);
            ll bsize = tree.size(tmpB);

            result[m-2-i] = result[m-1-i] - (asize * bsize);
            tree.unite(tmpA,tmpB);
        }
    }

    loop(i,m){
        cout << result[i] << endl;
    }

    return 0;
}