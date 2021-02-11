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
#include<unordered_map>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ll n;
    cin >> n;

    vector<int> a(n);
    loop(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    set<int> st;

    loop(i, n){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                if(j <= a[0]) st.insert(j);
                if(a[i] / j <= a[0]) st.insert(a[i] / j);
            }
        }
    }

    int ans = 0;

    for(int x:st){
        int g = 0;
        loop(i,n){
            if(a[i] % x == 0) g = gcd(a[i], g);
        }

        if(g == x) ans ++;
    }

    cout << ans << endl;
}