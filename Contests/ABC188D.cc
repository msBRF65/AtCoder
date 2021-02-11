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

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n,c;
    cin >> n >> c;

    vector<pair<ll, ll>> event;

    loop(i,n){
        ll a,b,c;
        cin >> a >> b >> c;

        event.emplace_back(a - 1,c);
        event.emplace_back(b, -c);
    }

    sort(event.begin(), event.end());

    ll ans = 0, t = 0, fee = 0;
    for(auto[x,y]: event){
        if(x != t){
            ans += min(c, fee) * (x - t);
            t = x;
        }
        fee += y;
    }

    cout << ans << endl;
}