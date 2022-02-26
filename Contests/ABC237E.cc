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

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> height(n);
    graph g(n);

    loop(i, n)
    {
        cin >> height[i];
    }
    loop(i, m)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> is_searched(n, false);
    vector<ll> climb_height(n, inf);

    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, 0});
    is_searched[0] = true;

    while (!q.empty())
    {
        auto [tmp_ch, tmp_node] = q.top();
        q.pop();
        if (climb_height[tmp_node] <= tmp_ch)
        {
            continue;
        }

        climb_height[tmp_node] = tmp_ch;

        for (ll nbr : g[tmp_node])
        {
            ll climb_to_nbr = 0;
            if (height[tmp_node] < height[nbr])
            {
                climb_to_nbr = height[nbr] - height[tmp_node];
            }
            ll nbr_ch = tmp_ch + climb_to_nbr;
            if (nbr_ch < climb_height[nbr])
            {
                q.push({nbr_ch, nbr});
                is_searched[nbr] = true;
            }
        }
    }

    ll ans = 0;
    loop(i, n)
    {
        ans = max(height[0] - height[i] - climb_height[i], ans);
    }

    cout << ans << endl;
    return 0;
}