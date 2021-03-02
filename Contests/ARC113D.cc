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

ll mod = 998244353;

ll pow_a(ll n, ll a){
    if(a == 1) return n % mod;
    if(n <= 1) return n;
    if(a % 2 == 1){
        ll tmp = pow_a(n, a / 2);
        tmp = tmp * tmp;
        tmp %= mod;
        return ((tmp * n) % mod);
    } else {
        ll tmp = pow_a(n, a / 2) % mod;
        return ((tmp * tmp) % mod);
    }
}

int main(){
    ll n,m,k;
    cin >> n >> m >> k;

    if(n == 1 && m == 1) {
        cout << k << endl;
        return 0;
    }

    if(n == 1) {
        ll ans = 0;
        for(int i = 1; i <= k; i++){
            ll tmp = pow_a(k - i + 1, m) - pow_a(k - i, m);
            while(tmp < 0){
                tmp += mod;
            }
            ans += tmp % mod;
            ans = ans % mod;
        }

        cout << ans << endl;
        return 0;
    }

    if(m == 1) {
        ll ans = 0;
        for(int i = 1; i <= k; i++){
            ll tmp = (pow_a(i,n) - pow_a(i - 1, n));
            while(tmp < 0){
                tmp += mod;
            }
            ans += tmp % mod;
            ans = ans % mod;
        }

        cout << ans << endl;
        return 0;
    }

    ll ans = 0;
    
    for(int i = 1; i <= k; i++){
        ll tmp = (pow_a(i,n) - pow_a(i - 1, n)) % mod;
        while(tmp < 0){
            tmp += mod;
        }
        tmp = tmp * (pow_a(k - i + 1, m) % mod);
        ans += tmp % mod;
        ans = ans % mod;
    }

    cout << ans << endl;
    return 0;
}