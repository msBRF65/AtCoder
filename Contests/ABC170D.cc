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
    ll n;
    cin >> n;

    vector<ll> a(n);
    loop(i,n){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll a_max = a[n-1];
    vector<bool> have_divisor(a_max + 1, false);

    ll before_num = 0;
    loop(i,n){
        ll c = 2;
        if(before_num == a[i]) c = 1;

        while(a[i] * c <= a_max){
            have_divisor[a[i] * c] = true;
            c++;
        }
        before_num = a[i];
    }

    ll result = 0;
    loop(i,n){
        if(!have_divisor[a[i]]) result ++;
    }

    cout << result << endl;
}