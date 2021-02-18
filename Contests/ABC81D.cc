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
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll max_a = 0;
    ll max_idx;
    ll min_a = 0;
    ll min_idx;

    loop(i,n){
        cin >> a[i];
        
        max_a = max(max_a, a[i]);
        if(max_a == a[i]) max_idx = i;

        min_a = min(min_a, a[i]);
        if(min_a == a[i]) min_idx = i;
    }

    cout << (n - 1) * 2 << endl;
    if(abs(max_a) >= abs(min_a)){
        loop(i,n){
            if(i != max_idx) cout << max_idx + 1 << " " << i + 1 << endl;
        }
        loop(i,n-1){
            cout << i + 1 << " " << i + 2 << endl;
        }
    }else{
        loop(i,n){
            if(i != min_idx) cout << min_idx + 1 << " " << i + 1 << endl;
        }
        loop(i, n-1){
            cout << n - i << " " << n - i - 1 << endl;
        }
    }
}