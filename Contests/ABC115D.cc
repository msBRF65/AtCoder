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

ll b_size[51] = {0};
ll p_size[51] = {0};

ll burger_size(int n){
    if(b_size[n] != 0) return b_size[n];
    if(n == 0){
        b_size[0] = 1;
        return 1;
    }
    b_size[n] = burger_size(n - 1) * 2 + 3;
    return b_size[n];
}

ll patty_size(int n){
    if(p_size[n] != 0) return p_size[n];
    if(n == 0){
        p_size[0] = 1;
        return 1;
    }
    p_size[n] = patty_size(n - 1) * 2 + 1;
    return p_size[n];
}

int main(){
    ll n,x;
    cin >> n >> x;

    ll tmp_level = n;
    ll ans = 0;

    while(x > 0){
        ll prev_level = tmp_level - 1;
        ll tmp_level_burger_size = burger_size(tmp_level);
        ll prev_level_burger_size = burger_size(prev_level);

        if(x >= tmp_level_burger_size - 1){
            ans += patty_size(prev_level) * 2 + 1; 
            break;
        }else if(x >= 2 + prev_level_burger_size){
            ans += patty_size(prev_level) + 1;
            x -= prev_level_burger_size + 2;
            tmp_level --;
        }else if(x == 1 + prev_level_burger_size){
            ans += patty_size(prev_level);
            break;
        }else{
            x --;
            tmp_level --;
        }
    }

    cout << ans << endl;
}