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
    ll q;
    cin >> q;
    vector<ll> a;
    vector<ll> ans;

    loop(i, q)
    {
        ll key;
        cin >> key;
        if (key == 1)
        {
            ll x;
            cin >> x;

            ll start = -1;
            ll end = ll(a.size());

            while (end - start > 1)
            {
                ll tmp = (start + end) / 2;
                if (a[tmp] >= x)
                {
                    end = tmp;
                }
                else
                {
                    start = tmp;
                }
            }

            a.insert(a.begin() + start + 1, x);
        }
        else
        {
            ll x, k;
            cin >> x >> k;

            ll start = -1;
            ll end = ll(a.size());

            if (key == 2)
            {
                x++;
            }

            while (end - start > 1)
            {
                ll tmp = (start + end) / 2;
                if (a[tmp] >= x)
                {
                    end = tmp;
                }
                else
                {
                    start = tmp;
                }
            }

            if (key == 2)
            {
                ll ans_id = start - (k - 1);
                if (ans_id >= 0 && ans_id <= ll(a.size() - 1))
                {
                    ans.push_back(a[ans_id]);
                }
                else
                {
                    ans.push_back(-1);
                }
            }
            else if (key == 3)
            {
                ll ans_id = end + (k - 1);
                if (ans_id <= ll(a.size() - 1))
                {
                    ans.push_back(a[ans_id]);
                }
                else
                {
                    ans.push_back(-1);
                }
            }
        }
    }

    loop(i, ll(ans.size()))
    {
        cout << ans[i] << endl;
    }

    return 0;
}
