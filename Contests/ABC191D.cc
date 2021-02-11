#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>

typedef long long ll;
typedef long double ld;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    double x_d, y_d, r_d;
    cin >> x_d >> y_d >> r_d;

    ll x, y, r;
    x = round(x_d * 10000);
    y = round(y_d * 10000);
    r = round(r_d * 10000);


    ll ans = 0;

    for(ll xx = -2e9; xx <= 2e9; xx += 10000){
        ll yy = r * r - (xx - x) * (xx - x);
        if(yy < 0) continue;
        ld y_w = sqrt(ld(yy));

        ll tmp_ans = floor(ld(y + y_w) / 10000) - ceil(ld(y - y_w) / 10000) + 1;

        if(tmp_ans > 0)ans += tmp_ans;
    }

    cout << ans << endl;
    return 0;
}