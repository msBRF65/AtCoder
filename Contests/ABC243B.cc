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
    vector<ll> a(n), b(n);
    ll ans_1 = 0, ans_2 = 0;
    loop(i, n)
    {
        cin >> a[i];
    }
    loop(i, n)
    {
        cin >> b[i];
        if (a[i] == b[i])
        {
            ans_1++;
        }
        loop(j,n){
            if(a[j] == b[i]) {
                ans_2 ++;
                break;
            }
        }
    }

    cout << ans_1 << endl;
    cout << ans_2 - ans_1 << endl;
}