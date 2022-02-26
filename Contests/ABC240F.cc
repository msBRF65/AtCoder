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

ll ans[200000];

ll solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), a(n + 1), b(n + 1);
    loop(i, n)
    {
        cin >> x[i] >> y[i];
    }

    ll res_m = m;
    ll ans = x[0];

    a[0] = 0;
    b[0] = 0;
    loop(i, n)
    {
        if (res_m < y[i])
        {
            y[i] = res_m;
        }

        b[i + 1] = b[i] + x[i] * y[i];
        a[i + 1] = a[i] + x[i] * y[i] * (y[i] + 1) / 2 + b[i] * y[i];

        if (b[i] > 0 && x[i] < 0)
        {
            ll max_id = min(b[i] / (-x[i]), y[i] - 1);
            ll max_a_1 = a[i] + x[i] * max_id * (max_id + 1) / 2 + b[i] * max_id;
            ll max_a_2 = a[i] + x[i] * (max_id + 1) * (max_id + 2) / 2 + b[i] * (max_id + 1);
            ll max_a = max(max_a_1, max_a_2);
            ans = max(ans, max_a);
        }
        else
        {
            ans = max(ans, a[i + 1]);
        }
        res_m -= y[i];
        if (res_m == 0)
        {
            break;
        }
    }

    return ans;
}

int main()
{
    ll T;
    cin >> T;

    loop(i, T)
    {
        ans[i] = solve();
    }

    loop(i, T)
    {
        cout << ans[i] << endl;
    }
}