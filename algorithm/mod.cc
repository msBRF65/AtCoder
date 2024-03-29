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

const ll MOD = 998244353;

ll dp[27][5001] = {0};

vector<ll> fac(5001), finv(5001), inv(5001);

void binom_init()
{
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < 5001; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
