#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)

using namespace std;

ll num = 1000000007;

ll multiplication(ll a, ll b){
    ll aa = a % num;
    ll bb = b % num;
    return (aa * bb) % num;
}

ll exp(ll x, ll n){
    if(n == 1)return x;
    if(n % 2 == 1) return multiplication(exp(x, n-1) ,x);
    ll tmp = exp(x, n/2);
    return multiplication(tmp, tmp);
}

ll factorial(ll a){
    ll result = 1;
    loop(i,a){
        result = multiplication(result, a-i);
    }
    return result;
}

ll combination(ll n,ll a){
    // x/y を求める 
    ll x = 1;
    // if(a * 2 > n) a = n-a;
    loop(i,a){
        x = multiplication(x, n-i);
    }
    ll factA = factorial(a);
    ll yRev = exp(factA, num -2);
    return multiplication(x,yRev);
}

int main(){
    ll n,a,b,result;
    cin >>n >>a >>b;
    result = exp(2,n);
    ll combA = combination(n,a);
    ll combB = combination(n,b);

    result = result - combA - combB - 1;
    while(result < 0){
        result += num;
    }

    cout << result << endl;
    
    return 0;
}