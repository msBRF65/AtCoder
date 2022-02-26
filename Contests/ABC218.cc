#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>
#include<set>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

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

struct Edge {
    ll a,b,c;
};

int main(){
    int n,m;
    cin >> n >> m;

    vector<Edge> edge_array(m);
    ll total_cost = 0;
    loop(i,m){
        cin >> edge_array[i].a >> edge_array[i].b >> edge_array[i].c;
        edge_array[i].a --;
        edge_array[i].b --;
        total_cost += edge_array[i].c; 
    }

    auto compare = [](const Edge l, const Edge r){
        return l.c <= r.c;
    };
    sort(edge_array.begin(),edge_array.end(), compare);

    UnionFind unionfind(n);

    ll graph_cost = 0;
    loop(i,m){
        Edge tmp = edge_array[i];
        if(unionfind.same(tmp.a, tmp.b) && tmp.c > 0) continue;
        unionfind.unite(tmp.a, tmp.b);
        graph_cost += tmp.c;
    }

    cout << total_cost - graph_cost << endl;
    return 0;
}