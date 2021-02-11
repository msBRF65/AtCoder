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
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n, m, q;
    cin >> n >> m >> q;

    vector<ll> train_map_init(n,0);
    vector<vector<ll>> train_map(n, train_map_init);

    loop(i, m) {
        ll l, r;
        cin >> l >> r;
        l --;
        r --;
        train_map[l][r] ++;
    }

    loop(i,n){
        for(int j = 1; j < n; j++){
            train_map[i][j] += train_map[i][j - 1];
        }
    }

    vector<P> questions;
    loop(i, q){
        ll l, r;
        cin >> l >> r;
        l --;
        r --;
        questions.emplace_back(l,r);
    }

    loop(i, q){
        ll l,r;
        tie(l, r) = questions[i];
        ll ans = 0;
        for(int j = l; j <= r; j++){
            if(l - 1 >= 0) ans += train_map[j][r] - train_map[j][l - 1];
            else ans += train_map[j][r];
        }
        cout << ans << endl;
    }
}