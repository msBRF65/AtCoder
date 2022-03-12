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
    ll n, x;
    string s;
    cin >> n >> x;
    cin >> s;

    deque<bool> dq;
    while(x > 0){
        dq.push_front(x % 2);
        x /= 2;
    }

    loop(i, n){
        if(s[i] == 'U'){
            dq.pop_back();
        }
        else if(s[i] == 'L'){
            dq.push_back(0);
        }
        else if(s[i] == 'R'){
            dq.push_back(1);
        }
    }

    ll ans = 0;
    while(!dq.empty()){
        ans = ans * 2 + dq.front();
        dq.pop_front();
    }

    cout << ans << endl;
}