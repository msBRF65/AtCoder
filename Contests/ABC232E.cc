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

int main()
{
    ll h, w, k;
    ll x1, y1, x2, y2;
    cin >> h >> w >> k;

    cin >> x1 >> y1 >> x2 >> y2;

    ll r, l, rl, nrl;

    r = 0;
    l = 0;
    rl = 0;
    nrl = 0;

    bool is_init_same_x = (x1 == x2);
    bool is_init_same_y = (y1 == y2);

    if (is_init_same_x && is_init_same_y)
    {
        rl++;
    }
    else if (is_init_same_x)
    {
        l++;
    }
    else if (is_init_same_y)
    {
        r++;
    }
    else
    {
        nrl++;
    }

    loop(i, k)
    {
        ll new_rl = (r + l) % MOD;
        ll new_l = (rl * (w - 1) + nrl) % MOD;
        ll new_r = (rl * (h - 1) + nrl) % MOD;
        ll new_nrl = (l * (h - 1) + r * (w - 1)) % MOD;
        if (h > 2 || w > 2)
        {
            new_nrl = (new_nrl + nrl * (h + w - 4)) % MOD;
        }
        if (h > 2)
        {
            new_r = (new_r + r * (h - 2)) % MOD;
        }
        if (w > 2)
        {
            new_l = (new_l + l * (w - 2)) % MOD;
        }
        rl = new_rl;
        l = new_l;
        r = new_r;
        nrl = new_nrl;
    }

    cout << rl << endl;
}