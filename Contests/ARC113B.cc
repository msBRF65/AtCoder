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

ll pow_mod(ll n, ll a, ll mod){
    if(a == 1) return n % mod;
    if(a % 2 == 1){
        ll tmp = pow_mod(n, a / 2, mod);
        return (tmp * tmp * n) % mod;
    } else {
        ll tmp = pow_mod(n, a / 2, mod);
        return (tmp * tmp) % mod;
    }
}


int main(){
    ll a, b, c;
    cin >> a >> b >> c;

    ll mod = pow_mod(b, c, 4);
    cout << pow_mod(a, mod + 4, 10) << endl;
}