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
    ll k;
    cin >> k;
    vector<ll> prime_num;

    ll ans = 0;

    loop(a, k){
        if((a + 1) > k / 2) {
            if((a + 1) == 1) ans += 1;
            else ans += 3;
            continue;
        }
        loop(b, a + 1){
            if((a + 1) * (b + 1) > k) break;
            loop(c, b + 1){
                ll tmp = (a+1) * (b+1) * (c+1);
                if(tmp <= k) {
                    if(a > b && b > c) ans += 6;
                    else if(a == b && b == c) ans += 1;
                    else ans += 3;
                }
                else break;
            }
        }
    }

    cout << ans << endl;
}