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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> try_num(n, -1);
    vector<ll> candy_num(n, -1);
    loop(i,n){
        cin >> a[i];
    }

    try_num[0] = 0;
    candy_num[0] = 0;
    ll candy = 0;
    ll final_try = 0;
    loop(i,n){
        candy += a[candy % n];
        if(try_num[candy % n] != -1){
            final_try = i + 1;
            break;
        }
        try_num[candy % n] = i + 1;
        candy_num[candy % n] = candy;
    }

    ll try_T = final_try - try_num[candy % n];
    ll candy_T = candy - candy_num[candy % n];
    
    ll T_num = (k - try_num[candy % n]) / try_T;
    
    candy = candy_num[candy % n] + (T_num * candy_T);
    ll tmp_k = T_num * try_T + try_num[candy % n];
   
    if(tmp_k < k){
        for(ll i = tmp_k + 1; i <= k; i++){
            candy += a[candy % n];
        }
    }

    cout << candy << endl;
    return 0;
}