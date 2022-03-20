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
    char s1, s2, s3;
    char t1, t2, t3;

    cin >> s1 >> s2 >> s3;
    cin >> t1 >> t2 >> t3;

    ll diff_num = 0;
    if (s1 != t1)
        diff_num++;
    if (s2 != t2)
        diff_num++;
    if (s3 != t3)
        diff_num++;

    if (diff_num == 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}