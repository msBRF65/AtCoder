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
    ll n, q;
    cin >> n >> q;

    vector<bool> is_searched(n + 1, false);
    graph g(n + 1);

    queue<ll> que;
    loop(i, q)
    {
        ll l, r;
        cin >> l >> r;
        if (l == 1)
        {
            is_searched[r] = true;
            que.push(r);
        }
        else
        {
            g[l - 1].push_back(r);
            g[r].push_back(l - 1);
        }
    }

    while (!que.empty())
    {
        ll tmp = que.front();
        que.pop();

        for (ll nbr : g[tmp])
        {
            if (is_searched[nbr] == false)
            {
                que.push(nbr);
                is_searched[nbr] = true;
            }
        }
    }

    if (is_searched[n] == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}