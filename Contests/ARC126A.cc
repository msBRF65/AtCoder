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

ll solve(){
    ll N2,N3,N4;
    cin >> N2 >> N3 >> N4;
    ll ans = 0;
    ll tmp = min(N4, N3 / 2);
    N4 -= tmp;
    N3 -= tmp * 2;
    ans += tmp;
    tmp = min(N3 / 2, N2 / 2);
    N3 -= tmp * 2;
    N2 -= tmp * 2;
    ans += tmp;
    tmp = min(N4 /2 , N2);
    N4 -= tmp * 2;
    N2 -= tmp; 
    ans += tmp;
    tmp = min(N2 / 3, N4);
    ans += tmp;
    N2 -= tmp * 3;
    N4 -= tmp;
    ans += N2 / 5;
    return ans;
}

int main(){
    ll T;
    cin >> T;
    vector<ll> ans;
    loop(i,T){
        ll tmp = solve();
        ans.push_back(tmp);
    }
    loop(i,T){
        cout << ans[i] << endl;
    }
}