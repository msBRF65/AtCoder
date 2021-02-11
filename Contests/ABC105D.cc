#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>
#include<unordered_map>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    loop(i,n) cin >> a[i];

    a[0] %= m;
    for(int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        a[i] %= m;
    }

    unordered_map<ll, ll> mod_num;
    mod_num[0] = 1;
    loop(i,n) {
        if(mod_num.count(a[i]) == 0)mod_num[a[i]] = 1;
        else mod_num[a[i]] ++;
    }

    ll ans = 0;
    for(auto i = mod_num.begin(); i != mod_num.end(); i ++) ans += i -> second * (i -> second - 1) / 2;

    cout << ans << endl;
}