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
    ll mod = 998244353;
    ll n,k;
    cin >> n >> k;

    vector<P> query(k);
    loop(i,k){
        ll l, r;
        cin >> l >> r;
        query[i] = P(l,r);
    }

    vector<ll> diff(n, 0);
    diff[0] = 1;
    diff[1] = -1;

    loop(i,n){
        if(i > 0) diff[i] += diff[i - 1];
        diff[i] = diff[i] % mod;
        if(diff[i] < 0) diff[i] += mod;
        loop(j, k){
            ll l, r;
            tie(l, r) = query[j];
            if(i + l < n) {
                diff[i + l] += diff[i];
            }
            if(i + r + 1 < n) {
                diff[i + r + 1] -= diff[i];
            }
        }
    }

    cout << diff[n-1] << endl;
}