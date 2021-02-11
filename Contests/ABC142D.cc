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

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

ll gcd(ll a,ll b){
    if(b == 0)return a;
    return gcd(b, a%b);
}

ll dividLimit(ll n,ll a){
    while(n % a == 0){
        n /= a;
    }
    return n;
}

int main(){
    ll a,b,gcdNum,result = 0,current = 2;
    cin >>a >>b;

    gcdNum = gcd(a,b);

    result ++;
    while(1){
        if(gcdNum % current == 0){
            gcdNum = dividLimit(gcdNum, current);
            result ++;
        }
        if(gcdNum < current * current){
            if(gcdNum != 1)result ++;
            break;
        }
        current ++;
    }
    
    cout << result << endl;
    return 0;
}