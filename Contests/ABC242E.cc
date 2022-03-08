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

ll mod_list[1000001];

ll solve(ll mod){
    ll n;
    string s;
    cin >> n >> s;

    bool is_complete_palindrome = true;
    ll mirror_size = s.size() / 2;
    loop(i, mirror_size){
        ll mirror_diff = s[mirror_size - i - 1] - s[s.size() - 1 - (mirror_size - i - 1)];
    
        if(mirror_diff > 0){
            is_complete_palindrome = false;
            break;
        } else if(mirror_diff < 0){
            break;
        }
    }

    if(s.size() % 2 == 1) mirror_size ++;
    ll ans = 0;
    loop(i, mirror_size){
        ll char_num = s[mirror_size - 1 - i]  - 'A';
        ans += char_num * mod_list[i];
        ans = ans % mod;
    }
    ans ++; // AAA... 
    
    if(is_complete_palindrome == false){
        ans = (ans + mod - 1) % mod;
    }
    return ans % mod;
}

int main(){
    ll t;
    cin >> t;
    vector<ll> ans(t);

    ll mod = 998244353;

    mod_list[0] = 1;
    for(ll i = 1; i < 1000001; i++){
        mod_list[i] = (mod_list[i - 1] * 26) % mod;
    }

    loop(i,t){
        ans[i] = solve(mod);
    }

    loop(i,t){
        cout << ans[i] << endl;
    }

    return 0;
}

// KVOHE EMSOZ ZASHE N DIGOJ RTJVM VSDWW