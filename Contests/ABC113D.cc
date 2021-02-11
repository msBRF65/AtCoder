#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;
ll mod = 10e8 + 7;

int main(){
    ll h, w, k;
    cin >> h >> w >> k;

    vector<ll> ptn(w,0);
    ptn[0] = 1;
    for(int i = 1; i < w; i++){
        ll i_ptn = 0;
        i_ptn += ptn[i - 1];
        if(i - 2 >= 0) i_ptn += ptn[i - 2];
        ptn[i] = i_ptn;
    }

    vector<ll> dp_init(w,0);
    vector<vector<ll>> dp(h + 1, dp_init);

    dp[0][0] = 1;

    for(int i = 1; i <= h; i++){
        loop(j, w){
            if(j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1] * (ptn[j - 1] * ptn[w - 1 - j]);
            if(j + 1 < w) dp[i][j] += dp[i - 1][j + 1] * (ptn[j] * ptn[w - j - 2]);
            dp[i][j] += dp[i - 1][j] * (ptn[j] * ptn[w - j - 1]);
            dp[i][j] %= mod;
        }
    }

    cout << dp[h][k - 1] << endl;
}