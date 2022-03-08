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
    string s;
    ll q;
    cin >> s >> q;

    vector<char> ans(q);

    loop(i,q){
        ll t, k;
        cin >> t >> k;

        ll cnt = 0;
        loop(j, t){
            if(k % 2 == 1) {
                cnt += 1;
                k = k / 2 + 1;
            } else {
                cnt += 2;
                k = k / 2;
            }
            if(k == 1){
                cnt += (t - j - 1);
                break;
            }
        }

        ll init_char_id = 0;
        if(s[k - 1] == 'A') {
            init_char_id = 0;
        } else if(s[k - 1] == 'B'){
            init_char_id = 1;
        } else {
            init_char_id = 2;
        }

        ll char_id = (init_char_id + cnt) % 3;

        if(char_id == 0) {
            ans[i] = 'A';
        } else if(char_id == 1){
            ans[i] = 'B';
        } else {
            ans[i] = 'C';
        }
    }

    loop(i, q){
        cout << ans[i] << endl;
    }

    return 0;
}