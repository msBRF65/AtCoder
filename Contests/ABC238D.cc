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

bool solve()
{
    ll a, s;
    cin >> a >> s;

    bool carry = false;
    bool is_succeed = true;
    while (a != 0 || s != 0)
    {
        bool tmp_a = a % 2;
        bool tmp_s = s % 2;
        if (tmp_a && tmp_s && carry)
        {
            carry = true;
        }
        else if (tmp_a && !tmp_s && !carry)
        {
            carry = true;
        }
        else if (!tmp_a && tmp_s && carry)
        {
            carry = false;
        }
        else if (!tmp_a && tmp_s && !carry)
        {
            carry = false;
        }
        else if (!tmp_a && !tmp_s && carry)
        {
            carry = true;
        }
        else if (!tmp_a && !tmp_s && !carry)
        {
            carry = false;
        }
        else
        {
            is_succeed = false;
            break;
        }

        a = a >> 1;
        s = s >> 1;
    }
    if (is_succeed && carry)
    {
        is_succeed = false;
    }
    return is_succeed;
}

int main()
{
    ll T;
    cin >> T;
    vector<bool> ans(T);
    loop(i, T)
    {
        ans[i] = solve();
    }
    loop(i, T)
    {
        if (ans[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}