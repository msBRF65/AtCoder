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
    vector<ll> x_num(500111, 0);

    string x;
    cin >> x;

    ll total = 0;
    loop(i, x.size())
    {
        x_num[i] = x[x.size() - 1 - i] - '0';
        total += x_num[i];
    }

    vector<ll> ans(x.size(), 0);

    loop(i, x.size())
    {
        ans[i] += total;
        total -= x_num[i];

        if (i != x.size() - 1)
        {
            ans[i + 1] = ans[i] / 10;
            ans[i] %= 10;
        }
    }

    loop(i, ans.size())
    {
        cout << ans[ans.size() - 1 - i];
    }
    cout << endl;
    return 0;
}