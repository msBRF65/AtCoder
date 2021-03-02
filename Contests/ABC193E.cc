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
#define inf 1e18
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b, a % b, y, x);
    y -= a/b * x;
    return d;
}

int main(){
    ll t;
    cin >> t;

    vector<ll> ans(t);
    vector<ll> x_arr, y_arr, p_arr, q_arr;
    loop(k,t){
        ll x,y,p,q;
        cin >> x >> y >> p >> q;
        x_arr.push_back(x);
        y_arr.push_back(y);
        p_arr.push_back(p);
        q_arr.push_back(q);
    }

    loop(k,t){
        ll x = x_arr[k];
        ll y = y_arr[k];
        ll p = p_arr[k];
        ll q = q_arr[k];

        ans[k] = -1;
        for(ll i = x; i < x + y; i++){
            for(ll j = p; j < p + q; j++){
                ll xx, yy;
                ll tmp_gcd = extgcd(2*x + 2*y, p + q, xx, yy);
                if((j - i) % tmp_gcd == 0){
                    ll unit = ((p + q) * (2*x + 2*y) / tmp_gcd);

                    yy =  ((-1 * yy) * ((j - i) / tmp_gcd)) % ((2*x + 2*y) / tmp_gcd);
                    ll tmp_ans = (p + q) * yy + j;
                    tmp_ans = tmp_ans % unit;

                    while(tmp_ans < p || tmp_ans < x){
                        tmp_ans += unit;
                    }
                    if(ans[k] == -1) ans[k] = tmp_ans;
                    else ans[k] = min(tmp_ans, ans[k]);
                }
            }
        }
    }

    loop(k,t){
        if(ans[k] == -1) cout << "infinity" << endl;
        else cout << ans[k] << endl;
    }
}