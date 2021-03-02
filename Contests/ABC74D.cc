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
    ll n;
    cin >> n;

    graph a(n), is_replaced(n);
    ll ans = 0;
    loop(i,n){
        loop(j,n){
            ll tmp;
            cin >> tmp;

            a[i].push_back(tmp);
            is_replaced[i].push_back(false);
            ans += tmp;
        }
    }

    ans /= 2;

    loop(i,n){
        for(ll j = i; j < n; j++){
            if(i == j) continue;
            ll min_dist = inf;
            loop(k,n){
                if(k == i || k == j) continue;
                min_dist = min(min_dist, a[i][k] + a[k][j]);
            }

            if(min_dist < a[i][j]){
                cout << -1 << endl;
                return 0;
            } else if(min_dist == a[i][j] && is_replaced[i][j] == false){
                ans -= a[i][j];
                is_replaced[i][j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}