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

struct edge {
    ll to;
    ll cost;

    edge(ll a, ll b){
        to = a;
        cost = b;
    }
};

int main(){
    ll n;
    cin >> n;
    
    vector<edge> edges;
    vector<vector<edge>> g(n, edges);

    loop(i, n-1){
        ll a, b, c;
        cin >> a >> b >> c;

        g[a - 1].emplace_back(b - 1,c);
        g[b - 1].emplace_back(a - 1,c);
    };

    ll q, k;
    cin >> q >> k;

    vector<ll> dist(n, inf);
    queue<ll> que;

    que.push(k - 1);
    dist[k - 1] = 0;

    while(!que.empty()){
        ll tmp_v = que.front();
        que.pop();

        for(edge e : g[tmp_v]){
            if(dist[e.to] == inf){
                dist[e.to] = dist[tmp_v] + e.cost;
                que.push(e.to);
            }
        }
    }

    vector<ll> x(q), y(q);

    loop(i, q){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    loop(i, q){
        cout << dist[x[i]] + dist[y[i]] << endl;
    }
}