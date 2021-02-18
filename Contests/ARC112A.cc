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
    ll t;
    cin >> t;

    vector<P> cases;

    loop(i,t){
        ll l,r;
        cin >> l >> r;
        cases.emplace_back(l,r);
    }

    loop(i,t){
        ll l,r;
        tie(l,r) = cases[i];

        if(l * 2 > r) cout << 0 << endl;
        else {
            ll range = (r - l * 2 + 1);
            ll ans = range * (range + 1) / 2;
            cout << ans << endl;
        }
    }
}