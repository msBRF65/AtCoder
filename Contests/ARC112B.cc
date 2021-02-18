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
    ll b,c;
    cin >> b >> c;

    ll ans = 0;
    
    if(c == 1) {
        if(b == 0) cout << 1 << endl;
        else cout << 2 << endl;
        return 0;
    }

    ll x = b - c / 2;// 2円払い続ける
    ll y = b + c / 2 - 1;  // 1円払う→2円払い続ける→1円払う


    ll z,w;
    if(c % 2 == 0){
        z = -1 * b - c / 2 + 1; // 1円払う→2円払い続ける
        w = -1 * b + c / 2 - 1; // 2円払い続ける→1円払う
    } else {
        z = -1 * b - c / 2;
        w = -1 * b + c / 2;
    }

    // (x, y),(z, w)
    if(y < z || w < x) ans = (y - x + 1) + (w - z + 1);
    else ans = max(y,w) - min(x,z) + 1;
    
    cout << ans << endl;
}