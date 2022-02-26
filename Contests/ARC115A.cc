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
    ll n, m;
    cin >> n >> m;
    ll odd = 0, even = 0;

    loop(i,n){
        string ss;
        cin >> ss;
        ll tmp = 0;
        loop(j, ss.size()){
            if(ss[j] == '1') tmp ++;
        }
        if(tmp % 2 == 0) even ++;
        else odd ++;
    }

    cout << odd * even << endl;
}