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

ll dp[200010][7] = {0};

int main(){
    ll n;
    string s,x;
    cin >> n >> s >> x;

    vector<ll> mod_7 = {0, 5, 3, 1, 6, 4, 2};

    dp[n][0] = 1;

    for(ll i = n - 1; i >= 0; i--){
        if(x[i] == 'T'){
            loop(j, 7){
                if(dp[i + 1][j] == 1){
                    dp[i][mod_7[j]] = 1;
                    ll a = j;
                    a -= (s[i] - '0');
                    while(a < 0) a += 7;
                    dp[i][mod_7[a]] = 1;
                }
            }
        } else {
            loop(j, 7){
                ll tmp = s[i] - '0';
                if(dp[i + 1][(j * 10) % 7] == 1 && dp[i + 1][(j * 10 + tmp) % 7] == 1){
                    dp[i][j] = 1;
                }
            }
        }
    }
    
    string ans;
    if(dp[0][0]) ans = "Takahashi";
    else ans = "Aoki";
    cout << ans << endl;
}