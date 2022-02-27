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

int n;
vector<P> vec;
bool used[20];
int a[20][20];

int calc()
{
    if (vec.size() == n)
    {
        int ret = 0;
        for (auto p : vec)
        {
            ret ^= a[p.first][p.second];
        }
        return ret;
    }

    int tmp;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!used[i])
        {
            tmp = i;
            break;
        }
    }
    used[tmp] = true;

    int ret = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!used[i])
        {
            vec.push_back({tmp, i});
            used[i] = true;
            ret = max(ret, calc());
            vec.pop_back();
            used[i] = false;
        }
    }

    used[tmp] = false;
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= 2*n - 1; i++){
        for(int j = i+1; j <= 2*n; j++){
            cin >> a[i][j];
        }
    }
    cout << calc() << endl;
}