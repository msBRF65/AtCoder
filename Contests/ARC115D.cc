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
    ll n, m;
    cin >> n >> m;

    vector<P> edges(m);
    loop(i,m){
        ll a,b;
        cin >> a >> b;
        edges.emplace_back(a-1, b-1);
    }

    vector<ll> max_degree(n);
    ll ans = 0;
    for(P edge: edges){
        ans += 
    }
}