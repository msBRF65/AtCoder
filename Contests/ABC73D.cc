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
    ll n, m, r;
    cin >> n >> m >> r;

    vector<vector<P>> edges(n);
    vector<ll> destinations(r);

    loop(i,r) {
        ll tmp;
        cin >> tmp;
        destinations[i] = tmp - 1;
    }

    loop(i,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a --;
        b --;

        edges[a].emplace_back(b,c);
        edges[b].emplace_back(a,c);
    }

    vector<vector<ll>> dist_map(n);

    loop(i,n){
        vector<ll> dist(n, inf);

        priority_queue<P> q;
        q.emplace(0,i);
        dist[i] = 0;

        while(!q.empty()){
            P v = q.top();
            q.pop();

            if(v.first > dist[v.second]) continue;
            for(P e: edges[v.second]){
                if(dist[e.first] > v.first + e.second){
                    dist[e.first] = v.first + e.second;
                    q.emplace(dist[e.first], e.first);
                }
            }
        }

        dist_map[i] = dist;
    }

    sort(destinations.begin(), destinations.end());
    ll ans = inf;
    do{
        ll tmp = 0;
        loop(i, r - 1){
            tmp += dist_map[destinations[i]][destinations[i+1]];
        }
        ans = min(tmp, ans);
    } while(next_permutation(destinations.begin(), destinations.end()));

    cout << ans << endl;
}