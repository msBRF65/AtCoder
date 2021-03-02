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

ll g1(ll n){
    vector<ll> a;
    while(1){
        a.push_back(n % 10);
        if(n < 10) break;
        n /= 10;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll ans = 0;
    loop(i, a.size()){
        ans = a[i] + ans * 10;
    }

    return ans;
}

ll g2(ll n){
    vector<ll> a;
    while(1){
        a.push_back(n % 10);
        if(n < 10) break;
        n /= 10;
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    loop(i, a.size()){
        ans = a[i] + ans * 10;
    }

    return ans;
}

ll f(ll n){
    return g1(n) - g2(n);
}

int main(){
    ll n,k;
    cin >> n >> k;

    loop(i, k){
        n = f(n);
    }

    cout << n << endl;
}