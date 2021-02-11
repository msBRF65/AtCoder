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

ll doXor(ll n){
    if(n % 2 == 1){
        ll count = (n + 1) / 2;
        return count % 2;
    }else{
        ll count = n / 2;
        if(count % 2 == 1){
            return n + 1;
        }else{
            return n;
        }
    }
};

int main(){
    ll a,b;
    cin >> a >> b;
    
    ll xora, xorb;
    if(a == 0) xora = 0;
    else xora = doXor(a-1);
    xorb = doXor(b);
    
    ll result = xora ^ xorb;

    cout << result << endl;
    return 0; 
}