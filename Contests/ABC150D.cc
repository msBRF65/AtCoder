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

ll gcd(ll a,ll b){
    return b? gcd(b,a%b):a;
}

ll lcm(ll a,ll b){
    return a * b/ gcd(a,b);
}

int f(ll n){
    ll res = 0;

    while(n % 2 == 0){
        n /= 2;
        res ++;
    }

    return res;
}

int main(){
    ll n,m;
    cin >>n >>m;

    vector<ll> a(n);
    loop(i,n) cin >>a[i];

    loop(i,n) {
        if (a[i] % 2 != 0) {
            cout << 0 << endl;
            return 0;
        }
        a[i] /= 2;
    }

    int t = f(a[0]);
    loop(i,n){
        if(t != f(a[i])){
            cout << 0 << endl;
            return 0;
        }

        a[i] >>= t;
    }
    m >>= t;

    ll l = 1;
    loop(i,n){
        l = lcm(l,a[i]);
        if(l > m){
            cout << 0 << endl;
            return 0;
        }
    }
    m /= l;
    ll ans = (m+1)/2;
    cout << ans << endl;

    return 0;
}