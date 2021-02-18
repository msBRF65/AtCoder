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

int main(){
    ll n,m;
    cin >> n >> m;

    vector<vector<P>> edges(n);
    vector<ll> dist(n, inf);

    loop(i,m){
        ll l,r,d;
        cin >> l >> r >> d;
        l --;
        r --;

        edges[l].emplace_back(r, d);
        edges[r].emplace_back(l, -d);
    };
    
    loop(i,n){
        if(dist[i] != inf) continue;

        queue<ll> q;

        q.push(i);
        dist[i] = 0;

        ll min_d = 0;
        ll max_d = 0;

        while(!q.empty()){
            ll tmp = q.front();
            q.pop();

            for(auto e: edges[tmp]){
                ll new_dist = dist[tmp] + e.second;
                if(dist[e.first] == inf) {
                    dist[e.first] = new_dist;
                    q.push(e.first);
                }
                else if(dist[e.first] != new_dist) {
                    cout << "No" << endl;
                    return 0;        
                }
                min_d = min(min_d, new_dist);
                max_d = max(max_d, new_dist);
            }

            if(max_d - min_d > 10e9){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}