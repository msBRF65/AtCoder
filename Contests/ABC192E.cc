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
#define inf 1e18
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct Edge {
    ll from;
    ll to;
    ll time;
    ll k;

    Edge(ll ff, ll tt, ll titi, ll kk){
        this -> from = ff;
        this -> to = tt;
        this -> time = titi;
        this -> k = kk;
    }
};

int main(){
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    x --;
    y --;

    vector<vector<Edge>> edges(n);
    vector<ll> dist(n, inf);
    
    loop(i,m){
        ll a, b, t, k;
        cin >> a >> b >> t >> k;

        edges[a - 1].emplace_back(a - 1, b - 1, t, k);
        edges[b - 1].emplace_back(b - 1, a - 1, t, k);
    }

    priority_queue<P> q;
    dist[x] = 0; 
    q.emplace(0, x);

    while(!q.empty()){
        P tmp = q.top();
        q.pop();

        if(dist[tmp.second] < tmp.first) continue;
        for(Edge e: edges[tmp.second]){
            ll new_time = e.time + ceil(tmp.first / double(e.k)) * e.k;
            if(new_time < dist[e.to]){
                dist[e.to] = new_time;
                q.emplace(new_time, e.to);
            }
        }
    }

    ll ans;
    if(dist[y] == inf) ans = -1;
    else ans = dist[y];

    cout << ans << endl;
}