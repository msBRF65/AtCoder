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

vector<ll> get_connected(ll n, ll h, ll w){
    vector<ll> ans;
    if(n - w >= 0) ans.push_back(n - w);
    if(n + w < h * w) ans.push_back(n + w);
    if(n % w != 0) ans.push_back(n - 1);
    if(n % w != w - 1) ans.push_back(n + 1);

    return ans;
}

ll get_ans(set<ll> is_used, queue<ll> is_not_used, ll remain_step, ll h, ll w){
    if(remain_step == 0) return 1;
    
    ll ans = 0;
    
    while(!is_not_used.empty()){
        ll i = is_not_used.front();
        is_not_used.pop();

        vector<ll> connected = get_connected(i, h, w);
        for(ll j: connected){
            if(is_used.count(j) != 0) continue;
            set<ll> new_is_used = is_used;

            new_is_used.insert(i);
            new_is_used.insert(j);

            ll tmp_ans = get_ans(new_is_used, is_not_used, remain_step - 1, h, w);

            ans += tmp_ans;
        }
    }

    return ans;
}

int main(){
    ll h, w, a, b;
    cin >> h >> w >> a >> b;

    set<ll> is_used;
    queue<ll> is_not_used;

    loop(i,h){
        loop(j,w){
            if(i % 2 == j % 2) is_not_used.push(i * w + j);
        }
    }

    cout << get_ans(is_used, is_not_used, a, h, w) << endl;    
}