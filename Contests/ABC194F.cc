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

ll dp[300000][18] = {0};
ll mod = 1000000007;

int main(){
    string n;
    ll k;
    cin >> n;
    cin >> k;
    
    vector<ll> num;
    for(char c: n){
        if(c >= 'A') num.push_back(c - 'A' + 10);
        else num.push_back(c - '0');
    }

    dp[0][1] = num[0] - 1;

    set<ll> s;
    loop(i, ll(num.size()) - 1){
        s.insert(num[i]);
        loop(j, 17){
            if(j == 1) dp[i+1][j] += 15;
            dp[i+1][j] += dp[i][j] * j;
            dp[i+1][j+1] += dp[i][j] * (16 - j);

            dp[i+1][j] %= mod;
            dp[i+1][j+1] %= mod;
        }

        loop(j, num[i+1]){
            if(s.count(j) != 0) dp[i+1][s.size()] ++;
            else dp[i+1][s.size()+1] ++;
        }
    }

    s.insert(num[num.size() - 1]);

    ll ans = dp[num.size() - 1][k];
    if(ll(s.size()) == k) ans ++;

    cout << ans % mod << endl;
    return 0;
}