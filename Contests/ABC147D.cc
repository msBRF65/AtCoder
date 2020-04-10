#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n, tmp, result = 0, pow = 1;
    ll mod = 1000000007;
    cin >>n;

    vector<ll> a(n);
    loop(i,n) cin >>a[i];

    loop(i,60){
        tmp = 0;
        loop(j,n){
            tmp += a[j] % 2;
            a[j] >>= 1;
        }
        ll add = tmp * (n - tmp) % mod;
        result += (add * pow);
        result %= mod;
        pow *= 2;
        pow %= mod;
    }

    cout << result << endl;
}