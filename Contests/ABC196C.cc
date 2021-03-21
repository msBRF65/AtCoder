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

ll get_ketasuu(ll n){
    ll ans = 1;
    while(n >= 10){
        ans ++;
        n /= 10;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 0;

    for(ll i = 1; i < 10000000; i++){
        // cout << i << " " << get_ketasuu(i) << endl;
        if(i + i * pow(10, get_ketasuu(i)) > n) break;
        ans ++;
    }

    cout << ans << endl;
}