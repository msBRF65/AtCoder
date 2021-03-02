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

bool enable_kill(ll t, ll a, ll b, vector<ll> h){
    ll cnt = 0; 
    loop(i,h.size()){
        if(h[i] <= b * t) break;
        cnt += (h[i] - (b * t) + a - b - 1) / (a - b);
        if(cnt > t || cnt >= 1e10) return false;
    }
    return cnt <= t;
};

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> h(n);
    loop(i,n) cin >> h[i];

    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());

    ll l = 0;
    ll r = 1e10;

    while(r - l > 1){
        ll tmp = (r + l) / 2;
        if(enable_kill(tmp,a,b,h)) r = tmp;
        else l = tmp;
    }

    cout << r << endl;
}