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

ll get_height(ll area, ll width)
{
    ll ans = area / width;
    if (area % width)
        ans++;
    return ans;
}

bool can_split_a(ll x, ll y, ll a, ll b, ll c)
{
    ll a_height = get_height(a, y);
    ll b_height = get_height(b, y);
    ll c_height = get_height(c, y);
    return (a_height + b_height + c_height) <= x;
}

bool can_split_b(ll x, ll y, ll a, ll b, ll c)
{
    ll a_width = get_height(a, x);
    if (a_width >= y)
        return false;
    ll b_height = get_height(b, y - a_width);
    ll c_height = get_height(c, y - a_width);
    return (b_height + c_height) <= x;
}

int main()
{
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    bool ans = false;
    ans = can_split_a(x, y, a, b, c) | ans;
    ans = can_split_a(y, x, a, b, c) | ans;
    ans = can_split_b(x, y, a, b, c) | ans;
    ans = can_split_b(x, y, b, a, c) | ans;
    ans = can_split_b(x, y, c, a, b) | ans;
    ans = can_split_b(y, x, a, b, c) | ans;
    ans = can_split_b(y, x, b, a, c) | ans;
    ans = can_split_b(y, x, c, a, b) | ans;

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}