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

ll c[2000][2000] = {0}, mod = 1000000007;


ll combination(int a, int b){
    if(c[a][b] != 0) return c[a][b];

    if(b == 0 || a == b){
        c[a][b] = 1;
        return 1;
    }
    if(b == 1){
        c[a][b] = a;
        return a;
    }
    ll tmp;
    tmp = combination(a-1,b) + combination(a-1,b-1);
    tmp %= mod;

    c[a][b] = tmp;
    return tmp;
}

int main(){
    int n,k,red,blue;
    cin >> n >> k;

    red = n - k;
    blue = k;

    ll result;

    for(int i = 1;i <= k; i++){
        if(red < i - 1){
            cout << "0" << endl;
            continue;
        }
        ll redGroup = combination(red+1, i);
        ll blueGroup = combination(blue-1, i-1);

        result = redGroup * blueGroup;
        result %= mod;

        cout << result << endl;
    }
}