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
#define inf 10e+12
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct edge{
    ll a;
    ll b;
    ll c;
};

int main(){
    ll n, m;
    cin >> n >> m;

    vector<edge> edges(m);
    graph g(n);

    loop(i, m){
        ll a,b,c;
        cin >> a >> b >> c;

        edge new_edge;
        new_edge.a = a - 1;
        new_edge.b = b - 1;
        new_edge.c = c;
        
        edges[i] = new_edge;
        g[new_edge.a].push_back(i);
    }

    loop(i,n){
        vector<ll> dist(n,inf);
        
        auto compare = [](P a, P b){ 
            return b.first < a.first || (!(a.first < b.first) && b.second < a.second);
        };
        priority_queue<P, vector<P>, decltype(compare)> q{compare};

        priority_queue<P> q;

        q.push(P(0, i));

        while(!q.empty()){
            P nd = q.top();
            q.pop();

            if(nd.first > dist[nd.second]) continue;
            for(ll k: g[nd.second]){
                edge tmp_edge = edges[k];

                ll arrival_time = nd.first + tmp_edge.c;

                if(arrival_time < dist[tmp_edge.b]){
                    dist[tmp_edge.b] = arrival_time;

                    q.push(P(arrival_time ,tmp_edge.b));
                }
            }
        }

        ll ans = -1;
        if(dist[i] != inf) ans = dist[i];
        cout << ans << endl;
    }
}