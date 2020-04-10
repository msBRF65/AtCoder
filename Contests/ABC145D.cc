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

ll mod = 1000000007;

ll multipy(ll a, ll b){
    return (a * b) % mod;
}

ll exp(ll x, ll n){
    if(n == 1)return x;
    if(n % 2 == 1) return multipy(exp(x,n-1) ,x );

    ll a = exp(x, n/2);
    return multipy(a,a);
}

// aCb
ll combination(ll a,ll b){
    if(b == 0)return 1;

    ll result = 1;

    for(ll i=a; i>a-b; i--){
        result = multipy(i,result);
    }

    ll bunbo = 1;
    for(ll i = 1; i <= b; i++){
        bunbo = multipy(bunbo,i);
    }


    bunbo = exp(bunbo, mod - 2);

    return multipy(bunbo, result);

}

int main(){
    ll x,y,a,b;
    cin >>x >>y;

    ll haveAnswer = 0;

    for(ll i = 0;i<= x;i++){
        a = i;
        if((x - i) % 2 == 1) continue;
        b = (x - i) / 2;
        if(y == b + a * 2) {
            haveAnswer = 1;
            break;
        }
    }

    
    if(!haveAnswer){
        cout << 0 << endl;
        return 0;
    }

    ll result;
    result =  combination(a+b,a);

    cout << result << endl;

    return 0;
}