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

ll get_divisor_num(ll n, ll i){
    if(i == 1) return 1;

    ll ans = 0;

    ll tmp = i;
    while(1){
        if(n % tmp == 0) {
            ans ++;
            tmp *= i;
        }
        else break;
    }

    return ans;
}

bool prime_checker(ll n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    ll n;
    cin >> n;

    vector<ll> is_prime(n + 1, 0);
    loop(i, n + 1) is_prime[i] = prime_checker(i);

    vector<ll> divisors(n + 1, 0);

    for(int i = 2; i <= n; i++){
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                if(is_prime[j])divisors[j] += get_divisor_num(i, j);
                if(j * j != i && is_prime[i / j]) divisors[i / j] += get_divisor_num(i, i / j);
            }
        }
    }

    vector<ll> sum_divisors(150, 0);

    vector<ll> div_num(150, 0);

    for(int i = n; i >= 2; i--){
        sum_divisors[divisors[i]] ++;
    }

    div_num[149] = sum_divisors[149];
    for(int i = 148; i >= 0 ; i--){
        div_num[i] = div_num[i + 1] + sum_divisors[i];
    }

    ll ans = 0;
    // 75
    ans += div_num[74];
    // 3 * 25
    ans += (div_num[2] - 1) * div_num[24];
    // 3 * 5 * 5
    ans += (div_num[2] - 2) * div_num[4] * (div_num[4] - 1) / 2;
    // 5 * 15
    ans += (div_num[4] - 1) * div_num[14];

    cout << ans << endl;
}