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

ll from = -inf;
ll to = inf;
ll diff = 0;

void f(ll n, vector<P> at){
    loop(idx,n){
        ll a = at[idx].first;
        ll t = at[idx].second;
        if(t == 1) diff += a;
        else if(t == 2) {
            if(from + diff < a && a < to + diff) from = a - diff;
            else if(a > to + diff) {
                from = a - diff;
                to = a - diff;
            }
        }
        else if(t == 3) {
            if(from + diff < a && a < to + diff) to = a - diff;
            else if(a < from + diff) {
                from = a - diff;
                to = a - diff;
            }
        }
    }
}

int main(){
    ll n;
    cin >> n;

    vector<P> at(n);
    loop(i,n) cin >> at[i].first >> at[i].second;

    ll q;
    cin >> q;
    vector<ll> x(q);
    loop(i,q) cin >> x[i];

    f(n, at);

    // debug(from);
    // debug(to);
    // debug(diff);

    loop(i,q){
        ll ans;
        if(x[i] < from) ans = from + diff;
        else if(x[i] > to) ans = to + diff;
        else ans = x[i] + diff;

        cout << ans << endl;
    }
}