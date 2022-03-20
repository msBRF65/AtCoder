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
    ll n;
    cin >> n;

    vector<bool> is_used(2 * n, false);
    ll tmp = 1;
    loop(i, n + 1)
    {
        while (is_used[tmp] == true)
        {
            tmp++;
        }
        cout << tmp << endl;
        is_used[tmp] = true;
        tmp ++;
        ll aoki_input;
        cin >> aoki_input;
        is_used[aoki_input] = true;
    }

    return 0;

}