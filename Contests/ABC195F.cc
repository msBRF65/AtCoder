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

ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

ll get_ans(ll a, ll b, set<ll> s, ll max, graph &g){
    ll ans = 0;
    // for(ll i: s) cout << i << " ";
    // cout << endl;

    for(ll tmp: g[max]){
        // debug(tmp);
        bool is_prime = true;
        for(ll ele: s){
            bool have_ele = false;
            loop(j, g[ele].size()){
                if(g[ele][j] == tmp) {
                    have_ele = true;
                    break;
                }
            }
            if(!have_ele) {
                is_prime = false;
                break;
            }
        }

        if(is_prime){
            set<ll> new_s = s;
            new_s.insert(tmp);
            ans ++;
            ans += get_ans(a, b, new_s, tmp, g);
        }
    }
    return ans;
}

int main(){
    ll a,b;
    cin >> a >> b;

    graph x(b - a + 1);

    for(ll i = a; i <= b - 1; i++){
        for(ll j = i + 1; j <= b; j ++){
            if(gcd(j, i) == 1) {
                x[i - a].push_back(j - a);
            }
        }
    }

    ll ans = b - a + 2;
    for(ll i = 0; i <= b - a - 1; i ++){
        set<ll> s;
        s.insert(i);

        ans += get_ans(a,b,s,i,x);
    }

    cout << ans << endl;
}