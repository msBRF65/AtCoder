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
    ll a,b;
    cin >> a >> b;

    if(a + b >=15 && b >= 8) cout << 1 << endl;
    else if(a + b >=10 && b >= 3) cout << 2 << endl;
    else if(a + b >= 3) cout << 3 << endl;
    else cout << 4 << endl;

    return 0;
}