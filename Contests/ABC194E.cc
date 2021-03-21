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
    ll n,m;
    cin >> n >> m;

    vector<P> a(n+1);
    loop(i,n){
        a[i].second = i;
        cin >> a[i].first;
    };
    a[n].first = inf;
    a[n].second = n;

    sort(a.begin(), a.end());

    if(a[0].first != 0){
        cout << 0 << endl;
        return 0;
    }
    if(a[0].second - (m - 1) >= 1){
        cout << 0 << endl;
        return 0;
    }


    P before_value = a[0];

    for(int i = 1; i <= n; i++){
        if(before_value.first == a[i].first){
            if(a[i].second - before_value.second > m){
                cout << before_value.first << endl;
                return 0;
            }
        }else{
            if(before_value.second + (m - 1) < (n - 1)){
                cout << before_value.first << endl;
                return 0;
            } else if(before_value.first + 1 < a[i].first){
                cout << before_value.first + 1 << endl;
                return 0;
            } else if(a[i].second - (m - 1) >= 1){
                cout << a[i].first << endl;
                return 0;
            }
        }
        before_value = a[i];
    }
}