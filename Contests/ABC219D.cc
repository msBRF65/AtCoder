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

int dp[301][301][301];

int main()
{
    int n, x, y;
    cin >> n;
    cin >> x >> y;

    vector<pair<int, int>> bento_array(n);

    loop(i, n)
    {
        cin >> bento_array[i].first >> bento_array[i].second;
    }

    loop(i, n + 1)
    {
        loop(j, x + 1)
        {
            loop(k, y + 1)
            {
                dp[i][j][k] = 1000;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> tmp = bento_array[i - 1];
        for (int j = 0; j < x + 1; j++)
        {
            for (int k = 0; k < y + 1; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        for (int j = 0; j < x + 1; j++)
        {
            for (int k = 0; k < y + 1; k++)
            {
                int next_x = min(x, j + tmp.first);
                int next_y = min(y, k + tmp.second);
                dp[i][next_x][next_y] = min(dp[i - 1][j][k] + 1, dp[i][next_x][next_y]);
            }
        }
    }

    int ans = dp[n][x][y];
    if (ans == 1000)
        ans = -1;
    cout << ans << endl;
    return 0;
}