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
    map<ll, vector<P>> m;

    cin >> n;
    vector<ll> x(n), y(n);
    string s;
    loop(i, n)
    {
        cin >> x[i] >> y[i];
    }
    cin >> s;
    // L: 0, R: 1

    loop(i, n)
    {
        P new_p = {x[i], s[i] == 'R'};
        m[y[i]].push_back(new_p);
    }

    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        vector<P> tmp_vec = iter->second;
        sort(tmp_vec.begin(), tmp_vec.end());
        bool exist_r = false;
        for (P tmp_P : tmp_vec)
        {
            if (exist_r && tmp_P.second == false)
            {
                cout << "Yes" << endl;
                return 0;
            }
            if (tmp_P.second == true && exist_r == false)
            {
                exist_r = true;
            }
        }
    }

    cout << "No" << endl;
}