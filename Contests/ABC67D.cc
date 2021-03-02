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
    ll n;
    cin >> n;

    graph edges(n);
    vector<ll> dist_f(n, inf), dist_s(n, inf);

    loop(i,n-1){
        ll a,b;
        cin >> a >> b;
        a --; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<P> q;

    q.emplace(0,0);
    dist_f[0] = 0;
    while(!q.empty()){
        P tmp = q.front();
        q.pop();

        for(ll v: edges[tmp.second]){
            if(dist_f[v] > tmp.first + 1){
                dist_f[v] = tmp.first + 1;
                q.emplace(tmp.first + 1, v);
            }
        }
    }

    q.emplace(0,n-1);
    dist_s[n-1] = 0;
    while(!q.empty()){
        P tmp = q.front();
        q.pop();

        for(ll v: edges[tmp.second]){
            if(dist_s[v] > tmp.first + 1){
                dist_s[v] = tmp.first + 1;
                q.emplace(tmp.first + 1, v);
            }
        }
    }

    ll cnt = 0;
    loop(i,n){
        if(dist_f[i] <= dist_s[i]) cnt++;
        else cnt--;
    }

    if(cnt > 0) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}