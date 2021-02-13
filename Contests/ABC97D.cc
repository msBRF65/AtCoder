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
    ll n, m;
    cin >> n >> m;

    vector<ll> p(n);
    loop(i,n) cin >> p[i], p[i]--;

    vector<ll> is_searched(n, false);
    vector<vector<ll>> g(n);

    loop(i,m){
        ll x, y;
        cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<ll> q;
    ll ans = 0;

    ll next_v = 0;

    while(1){
        set<ll> s;

        for(int i = next_v; i < n; i++){
            if(!is_searched[i]) {
                q.push(i);
                is_searched[i] = true;
                s.insert(i);
                next_v = i + 1;
                break;
            }
        }

        if(q.empty()) break;

        while(!q.empty()){
            ll tmp = q.front();
            q.pop();

            for(ll v: g[tmp]){
                if(!is_searched[v]){
                    q.push(v);
                    is_searched[v] = true;
                    s.insert(v);
                }
            }
        }

        for(auto x: s){
            if(s.count(p[x]) == 1) ans ++;
        }
    }

    cout << ans << endl;
}