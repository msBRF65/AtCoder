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

bool prime_cheker(int n){
    if(n == 0 || n == 1) return false;
    if(n == 2 || n == 3) return true;

    int tmp = 2;
    while(tmp * tmp <= n){
        if(n % tmp == 0) return false;
        tmp ++;
    }

    return true;
}

bool is_prime[100010];
int sum_similar[100010];

int main(){
    ll q;
    cin >> q;

    vector<pair<int, int>> query;
    loop(i, q){
        int l,r;
        cin >> l >> r;
        query.emplace_back(l, r);
    }

    int array_size = 100010;
    loop(i, array_size){
        is_prime[i] = prime_cheker(i);
    }
    sum_similar[0] = 0;
    loop(i, array_size - 1){
        sum_similar[i + 1] = sum_similar[i];
        if(i % 2 == 0 && is_prime[i + 1] && is_prime[(i + 2) / 2]){
            sum_similar[i + 1] ++;
        }
    }

    loop(i, q){
        cout << sum_similar[query[i].second] - sum_similar[query[i].first - 1] << endl;
    }

    return 0;
}