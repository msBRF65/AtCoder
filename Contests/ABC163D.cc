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

int main(){
    ll n,k, count = 0;
    cin >> n >> k;
    
    for(ll i = k; i <= n+1; i++){
        ll min, max;
        min = (i - 1) * i / 2;
        max = (n + n - i + 1) * i / 2;

        count += max - min + 1;
        count %= mod;
    }

    cout << count << endl;
}