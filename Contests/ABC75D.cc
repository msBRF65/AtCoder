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
    ll n, k;
    cin >> n >> k;
    vector<P> points;

    loop(i,n) {
        ll x, y;
        cin >> x >> y;
        points.emplace_back(x,y);
    }

    ll ans = 4e+18;

    loop(i,n){
        for(ll j = i; j < n; j++){
            P x_range = P(min(points[i].first, points[j].first), max(points[i].first, points[j].first));
            loop(ii,n){
                for(ll jj = ii; jj < n; jj++){
                    P y_range = P(min(points[ii].second, points[jj].second), max(points[ii].second, points[jj].second));
                    ll cnt = 0;
                    loop(k,n){
                        bool x_in_range = x_range.first <= points[k].first && points[k].first <= x_range.second;
                        bool y_in_range = y_range.first <= points[k].second && points[k].second <= y_range.second;
                        
                        if(x_in_range && y_in_range) cnt ++;
                    }

                    if(cnt >= k) ans = min(ans, (x_range.second - x_range.first) * (y_range.second - y_range.first));
                }
            }

        }
    }

    cout << ans << endl;
}