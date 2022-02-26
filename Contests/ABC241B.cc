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
    vector<ll> a(n), b(m);

    loop(i, n)
    {
        cin >> a[i];
    }
    loop(i, m)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    ll a_id = -1;
    ll b_id = -1;
    loop(i, m)
    {
        while (a_id < n)
        {
            if (a[a_id] == b[i])
            {
                b_id = i;
                a_id++;
                break;
            }
            a_id++;
        }
    }

    if (a_id <= n && b_id == m - 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}