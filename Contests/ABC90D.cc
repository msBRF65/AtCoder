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

int main(){
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    ll b = k + 1;

    while(b <= n){
        ans += int(n / b) * (b - k);
        if(k == 0) ans --;
        if(n % b >= k) ans += n % b - k + 1;

        b++;
    }

    cout << ans << endl;
}