#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <deque>
#include <map>
#include <queue>
#include <cmath>
#include <set>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n)        \
    for (ll i = 0; i < n; i++) \
    {                          \
        cout << a[i] << ' ';   \
    }                          \
    cout << endl;
#define inf 100000000000
#define loop(i, n) for (ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll, ll>

using namespace std;

ll dp[2001][2000][2];
const ll MOD = 998244353;

int main()
{
    ll n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--;
    t--;
    x--;

    vector<vector<ll>> g(n);
    loop(i, m)
    {
        ll u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    loop(i, k + 1)
    {
        loop(j, n)
        {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    dp[0][s][0] = 1;

    for (ll i = 1; i <= k; i++)
    {
        loop(j, n)
        {
            for (ll adj : g[j])
            {
                if (adj == x)
                {
                    dp[i][adj][0] += dp[i - 1][j][1];
                    dp[i][adj][1] += dp[i - 1][j][0];
                }
                else
                {
                    dp[i][adj][0] += dp[i - 1][j][0];
                    dp[i][adj][1] += dp[i - 1][j][1];
                }
                dp[i][adj][0] %= MOD;
                dp[i][adj][1] %= MOD;
            }
        }
    }

    cout << dp[k][t][0] << endl;
    return 0;
}