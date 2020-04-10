#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n;
    cin >>n;
    vector<ll> a(n);
    loop(i,n) cin >>a[i]; 

    ll currentNum = 1;
    ll ans = 0;

    loop(i,n){
        if(a[i] == currentNum) currentNum++;
        else ans++;
    }

    if(ans == 0 && a[0] == 1){
        cout << 0 << endl;
        return 0;
    }

    if(ans == 0 || ans == n){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

}