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

bool is_prime(ll n){
    if(n == 1) return true;
    if(n == 2) return true;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    
    vector<ll> prime_arr;
    for(ll i = 2; i <= n; i++){
        if(is_prime(i)) prime_arr.push_back(i);
    }
    a[0] = 1;
    for(ll i = 2; i <= n; i++){
        ll tmp_num = i;
        ll tmp_ans = 0;
        for(ll prime: prime_arr){
            if(prime > tmp_num) break;
            while(tmp_num % prime == 0){
                tmp_ans ++;
                tmp_num /= prime;
            }
        }
        a[i - 1] = tmp_ans + 1;
    }

    loop(i,n) cout << a[i] << " ";
    cout << endl;
    return 0;
}