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
    ll x;
    cin >> x;

    if(x < 10){
        cout << x << endl;
        return 0;
    }

    ll num_digits = 1;
    ll pow_10_num_digits = 10;
    while((x / pow_10_num_digits) >= 10){
        num_digits ++;
        pow_10_num_digits *= 10;
    }
    num_digits ++;

    for (ll i = 1; i < 10; i++)
    {
        loop(j, 10)
        {
            bool success = true;

            ll tmp = j;
            ll diff = j - i;
            ll ans = i;
            loop(k, num_digits - 1){
                if(tmp >= 10 || tmp < 0){
                    break;
                }
                ans = ans * 10 + tmp;
                tmp += diff;
            }
            if(ans >= x){
                cout << ans << endl;
                return 0;
            }
        }
    }

    //99 99999 99999 99998
}