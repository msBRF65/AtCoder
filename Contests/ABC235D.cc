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

ll ll_pow(ll e, ll n)
{
    ll result = 1;
    loop(i, n)
    {
        result *= e;
    }
    return result;
}

ll reverse(ll a)
{
    ll rank_num = to_string(a).size();
    ll a_top_num = a / pow(10, rank_num - 1);
    ll result = a * 10 - a_top_num * ll_pow(10, rank_num);
    result += a_top_num;
    return result;
}

int main()
{
    ll a, n;
    cin >> a >> n;
    bool is_searched[1000010] = {false};

    priority_queue<P, vector<P>, greater<P>> q; // try_num, x
    q.push({0,n});
    is_searched[n] = true;

    ll ans = inf;
    while (!q.empty())
    {
        auto [try_num, x] = q.top();
        // cout << x << " " << try_num << endl;
        q.pop();
        if (try_num + 1 >= ans)
        {
            continue;
        }

        if (x % a == 0)
        {
            if (x / a == 1)
            {
                cout << try_num + 1 << endl;
                return 0;
            }
            else
            {
                if(!is_searched[x/a]){
                    is_searched[x/a] = true;
                    q.push({try_num + 1, x/a});
                }
            }
        }

        if (x > 10)
        {
            string x_str = to_string(x);
            if (x_str[1] == 0)
            {
                continue;
            }
            ll rev_x = reverse(x);
            if(!is_searched[rev_x]){
                is_searched[rev_x] = true;
                q.push({try_num + 1, rev_x});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}