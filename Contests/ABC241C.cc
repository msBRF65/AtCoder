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

    vector<string> s(n);
    loop(i, n)
    {
        cin >> s[i];
    }

    loop(i, n - 5)
    {
        loop(j, n)
        {
            // 横
            ll cnt = 0;
            loop(k, 6)
            {
                if (s[j][i + k] == '#')
                {
                    cnt++;
                }
            }
            if (cnt >= 4)
            {
                cout << "Yes" << endl;
                return 0;
            }

            // 縦
            cnt = 0;
            loop(k, 6)
            {
                if (s[i + k][j] == '#')
                {
                    cnt++;
                }
            }
            if (cnt >= 4)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    loop(i, n - 5)
    {
        loop(j, n - 5)
        {
            // ななめ
            ll cnt = 0;
            loop(k, 6)
            {
                if (s[j + k][i + k] == '#')
                {
                    cnt++;
                }
            }
            if (cnt >= 4)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    loop(i, n - 5)
    {
        loop(j, n - 5)
        {
            // ななめ
            ll cnt = 0;
            loop(k, 6)
            {
                if (s[j + k][i + k] == '#')
                {
                    cnt++;
                }
            }
            if (cnt >= 4)
            {
                cout << "Yes" << endl;
                return 0;
            }

            cnt = 0;
            loop(k, 6)
            {
                if (s[j + k][(n - 1) - (i + k)] == '#')
                {
                    cnt++;
                }
            }
            if (cnt >= 4)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}