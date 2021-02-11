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
    ll n, k;
    cin >> n >> k;

    vector<ll> p(n),c(n);

    loop(i,n){
        cin >> p[i];
        p[i]--;
    }
    loop(i,n){
        cin >> c[i];
    }

    ll ans = -inf;
    
    loop(i,n){
        ll start = i;
        vector<ll> cycle;
        ll sum_cycle_score = 0;
        ll now = start;

        do{
            cycle.push_back(now);
            sum_cycle_score += c[now];

            now = p[now];        
        }while(now != start);

        ll path = 0;
        ll cnt = 0;

        while(true){
            cnt ++;
            path += c[now];

            if(cnt > k) break;

            ll num = (k - cnt) / cycle.size();
            ll score = path + max(0ll, sum_cycle_score) * num;

            ans = max(ans, score);

            now = p[now];
            if(now == start) break;
        }

    }

    cout << ans << endl;
}