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

class Dinic {
private:
    struct Edge {
        ll from;
        ll to;
        ll capacity;
        ll rev;

        Edge(ll f, ll t, ll c, ll r){
            this -> from = f;
            this -> to = t;
            this -> capacity = c;
            this -> rev = r;
        }
    };
    vector<vector<Edge>> g;
    vector<ll> distance, iter;
    ll infinity = 1e18;

    bool have_path(ll s, ll t){
        distance.assign(g.size(), -1);
        queue<ll> q;

        q.push(s);
        distance[s] = 0;

        while(!q.empty() && distance[t] == -1){
            ll tmp_v = q.front();
            q.pop();

            for(Edge e: g[tmp_v]){
                if(e.capacity > 0 && distance[e.to] == -1) {
                    q.push(e.to);
                    distance[e.to] = distance[e.from] + 1;
                }
            }
        }

        return distance[t] != -1;
    }

    ll get_flow(ll s, ll t, ll max_f){
        if(s == t) return max_f;
        for(ll &i = iter[s]; i < g[s].size(); i++){
            Edge &e = g[s][i];
            if(e.capacity > 0 && distance[e.from] < distance[e.to]){
                ll f = get_flow(e.to, t, min(max_f, e.capacity));
                if(f > 0){
                    e.capacity -= f;
                    g[e.to][e.rev].capacity += f;
                    return f;
                }
            }
        }
        return 0;
    }

public:
    Dinic(ll v_size){
        g.assign(v_size, vector<Edge>());
    };

    void add_edge(ll from, ll to, ll c){
        g[from].emplace_back(from, to, c, g[to].size());
        g[to].emplace_back(to, from, c, g[from].size() - 1);
    }

    ll get_max_flow(ll s, ll t){
        ll max_flow = 0;
        while(have_path(s,t)){
            iter.assign(g.size(), 0);
            ll flow = get_flow(s, t, infinity);
            while(flow > 0){
                max_flow += flow;
                flow = get_flow(s,t, infinity);
            };
        }

        return max_flow;
    }
};

int main(){
    ll n;
    cin >> n;

    graph color(n);
    loop(i,n){
        string s;
        cin >> s;
        loop(j,n){
            if(s[j] == 'B') color[i].push_back(1);
            else if(s[j] == 'W') color[i].push_back(-1);
            else color[i].push_back(0);
        }
    }

    Dinic dinic(n * n + 2);
    // s: 0, t:n^2 + 1
    loop(i,n){
        loop(j,n){
            ll v_num = i * n + (j+1);
            if(j != n - 1) {
                dinic.add_edge(v_num, v_num + 1, 1);
            }
            if(i != n - 1) {
                dinic.add_edge(v_num, v_num + n, 1);
            }
            
            if(color[i][j] != 0){
                ll from, to;
                if((i + j) % 2 == 0 && color[i][j] == 1) {from = 0; to = v_num;}
                else if((i + j) % 2 == 1 && color[i][j] == 1) {from = n*n + 1; to = v_num;}
                else if((i + j) % 2 == 0 && color[i][j] == -1) {from = n*n + 1; to = v_num;}
                else if((i + j) % 2 == 1 && color[i][j] == -1) {from = 0; to = v_num;}

                dinic.add_edge(to, from, inf);
            }
        }
    }

    ll ans = 2 * n * (n-1);
    ans -= dinic.get_max_flow(0, n*n+1);

    cout << ans << endl;
}