#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>
#include<set>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n, c;
    cin >> n >> c;

    vector<P> sushi(n);

    loop(i,n){
        ll x, v;
        cin >> x >> v;
        sushi[i] = P(x,v);
    }

    sort(sushi.begin(), sushi.end());

    ll last_cal = 0;
    ll last_x = 0;

    vector<P> max_cal_r = {P(0,0)};

    loop(i,n){
        last_cal = last_cal + sushi[i].second - (sushi[i].first - last_x);
        last_x = sushi[i].first;

        P new_max_cal = max_cal_r[max_cal_r.size() - 1];
        if(last_cal > new_max_cal.second){
            new_max_cal.second = last_cal;
            new_max_cal.first = last_x;
        }
        max_cal_r.push_back(new_max_cal);
    }

    last_cal = 0;
    last_x = c;
    vector<P> max_cal_l = {P(c,0)};

    loop(i,n){
        last_cal = last_cal + sushi[n - 1 - i].second - (last_x - sushi[n - 1 - i].first);
        last_x = sushi[n - 1 - i].first;
        
        P new_max_cal = max_cal_l[max_cal_l.size() - 1];
        if(last_cal > new_max_cal.second){
            new_max_cal.second = last_cal;
            new_max_cal.first = last_x;
        }
        max_cal_l.push_back(new_max_cal);
    }

    ll ans = 0;
    loop(i, n + 1){
        ans = max(ans, max_cal_r[i].second + max_cal_l[n - i].second - min(max_cal_r[i].first, c - max_cal_l[n - i].first));
    }

    cout << ans << endl;
}