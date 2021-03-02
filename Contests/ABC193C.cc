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
    ll n;
    cin >> n;

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<bool> used(100010, false);

    ll ans = n;
    for(ll i = 2; i * i <= n; i++){
        if(!used[i]){
            ll cnt = 0;
            ll tmp = i;
            while(tmp <= n){
                cnt ++;
                tmp *= i;
            }
            ans -= (cnt - 1);

            for(ll j = i; j < 100010; j *= i) used[j] = true;
        }
    }

    cout << ans << endl;
    return 0;
}