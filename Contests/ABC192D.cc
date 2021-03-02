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
typedef long double ld;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 1000000000000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

ll get_num(ll d, vector<ll> x_vec){
    ll ans = 0;
    for(ll x: x_vec){
        if(ld((inf - x) / d) < ans) {
            return inf + 10;
        }
        ans = ans * d + x;
    }

    return ans;
}

int main(){
    string x;
    ll m;
    cin >> x;
    cin >> m;

    if(x.size() == 1) {
        if(stoi(x) <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    vector<ll> x_vec;

    ll d = 0;
    loop(i, ll(x.size())){
        ll tmp = ll(x[i] - '0');
        d = max(d, tmp);
        x_vec.push_back(tmp);
    }

    ll l = 0;
    ll r = inf + 1;

    while(r - l > 1){
        ll tmp = (r + l) / 2;
        if(get_num(tmp, x_vec) > m) r = tmp;
        else l = tmp;
    }

    ll ans = 0;
    if(l > d) ans = l - d;

    cout << ans << endl;
    return 0;
}