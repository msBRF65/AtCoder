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
    ll k;
    cin >> k;

    vector<ll> ans(50);
    loop(i,50) ans[i] = i + k / 50;

    loop(i, k % 50){
        ans[i] += 50;
        loop(j,50){
            if(j != i) ans[j] --;
        }
    }

    cout << 50 << endl;
    loop(i, 50) cout << ans[i] << " ";
    cout << endl;
}