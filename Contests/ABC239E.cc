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
#include <stack>

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
    ll n, q;
    cin >> n >> q;

    vector<ll> x(n);
    loop(i, n)
    {
        cin >> x[i];
    }

    vector<vector<ll>> subtree_x(n);

    vector<bool> is_searched(n, false);
    graph g(n);
    loop(i, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    stack<ll> st;
    st.push(0);
    is_searched[0] = true;
    while (!st.empty())
    {
        ll tmp = st.top();
        bool searched_subtree = true;
        for (ll child : g[tmp])
        {
            if (is_searched[child] == false)
            {
                is_searched[child] = true;
                st.push(child);
                searched_subtree = false;
            }
        }

        if (searched_subtree)
        {
            st.pop();
            vector<ll> tmp_subtree_x;
            tmp_subtree_x.push_back(x[tmp]);
            for (ll child : g[tmp])
            {
                for (ll child_subtree_x : subtree_x[child])
                {
                    tmp_subtree_x.push_back(child_subtree_x);
                }
            }
            sort(tmp_subtree_x.begin(), tmp_subtree_x.end(), greater<ll>{});
            ll subtree_num = min(ll(20), ll(tmp_subtree_x.size()));
            loop(i, subtree_num)
            {
                subtree_x[tmp].push_back(tmp_subtree_x[i]);
            }
        }
    }

    vector<ll> ans(q);
    loop(i, q)
    {
        ll v, k;
        cin >> v >> k;
        ans[i] = subtree_x[v - 1][k - 1];
    }

    loop(i, q)
    {
        cout << ans[i] << endl;
    }

    return 0;
}