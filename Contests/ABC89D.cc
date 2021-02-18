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

ll power_consumption(P a, P b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ll h, w, d;
    cin >> h >> w >> d;

    vector<P> num_masu(h * w);

    loop(i,h){
        loop(j,w){
            ll a;
            cin >> a;
            num_masu[a - 1] = P(i,j);
        }
    }

    ll q;
    cin >> q;
    vector<P> test(q);
    loop(i,q){
        ll l,r;
        cin >> l >> r;
        l --;
        r --;
        test[i] = P(l,r);
    }

    vector<ll> sum_consumption(h * w, 0);
    loop(i, h*w){
        if(i - d < 0) sum_consumption[i] = 0;
        else sum_consumption[i] = sum_consumption[i - d] + power_consumption(num_masu[i], num_masu[i - d]);
    }

    loop(i,q){
        ll l,r;
        tie(l,r) = test[i];
        cout << sum_consumption[r] - sum_consumption[l] << endl;
    }
}