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
#define inf 1e18
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;
ll dp[100][101][100] = {0};


int main(){
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    loop(i,n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    ll ans = inf;

    for(ll l = 1; l <= n; l++){//　使用する種類
        loop(i,100){
            loop(j,101){
                loop(k, 100){
                    dp[i][j][k] = 0;
                }
            }
        }


        loop(i,n){ // i番目まで
            if(i == 0){
                dp[0][1][a[0] % l] = a[0];
                continue;
            }
            loop(j, 101){
                loop(k, 100){
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
            for(ll j = 2; j < l + 1; j++){ // j個
                loop(k,l){ // mod l で k になる取り方で最大
                    if(dp[i - 1][j - 1][k] != 0){
                        dp[i][j][(k + a[i]) % l] = max(dp[i - 1][j - 1][k] + a[i], dp[i][j][(k + a[i]) % l]);
                    }
                }
            }
        }

        // debug(l);
        // loop(i,n)loop(j,n+1)loop(k,n) cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;

        // debug((x - dp[n-1][l][x % l]) / l);
        if(dp[n-1][l][x % l] != 0) ans = min(ans, (x - dp[n-1][l][x % l]) / l);
    }

    cout << ans << endl;
}