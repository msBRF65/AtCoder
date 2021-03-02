#include<iostream>
#include<vector>
#include<queue>

typedef long long ll;

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