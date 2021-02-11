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

int main(){
    ll h, w;
    cin >> h >> w;

    ll c[10][10];

    loop(i,10){
        loop(j,10){
            cin >> c[i][j];
        }
    };

    auto compare = [](P a, P b){ 
        return b.first < a.first || (!(a.first < b.first) && b.second < a.second);
    };
    priority_queue<P, vector<P>, decltype(compare)> q{compare};
    ll dist[10];

    loop(i, 10) dist[i] = inf;

    q.push(P(0,1));
    
    while(!q.empty()){
        P tmp = q.top();
        q.pop();

        if(dist[tmp.second] < tmp.first) continue;
        loop(i,10){
            ll tmp_cost = tmp.first + c[i][tmp.second];
            if(tmp_cost < dist[i]){
                dist[i] = tmp_cost;
                q.push(P(tmp_cost, i));
            }
        }
    }

    ll ans = 0;
    loop(i,h){
        loop(j,w){
            ll tmp_a;
            cin >> tmp_a;

            if(tmp_a != -1) ans += dist[tmp_a];
        }
    }

    cout << ans << endl;
}