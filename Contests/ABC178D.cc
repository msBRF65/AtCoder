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
ll mod = 1000000007;
ll combi_map[3001][2001] = {0};

ll combination(int a, int b){
    if(a < b) return 0;
    if(combi_map[a][b] != 0) return combi_map[a][b];

    if(b == 0 || a == b){
        combi_map[a][b] = 1;
        return 1;
    }
    if(b == 1){
        combi_map[a][b] = a;
        return a;
    }
    ll tmp;
    tmp = combination(a-1,b) + combination(a-1,b-1);
    tmp %= mod;

    combi_map[a][b] = tmp;
    return tmp;
}

int main(){
    ll s;
    cin >> s;

    ll c = 1;
    ll ans = 0;
    while(c * 3 <= s){
        ll surplus = s - c * 3;
        ans += combination(surplus + c - 1, c - 1);
        ans %= mod;

        c ++;
    }

    cout << ans << endl;
}