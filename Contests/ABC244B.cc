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
    ll n;
    cin >> n;
    string t;
    cin >> t;
    ll dx = 1;
    ll dy = 0;
    ll x = 0;
    ll y = 0;
    loop(i, t.size()){
        if(t[i] == 'S') {
            x += dx;
            y += dy;
        } else {
            if(dx == 1){
                dx = 0;
                dy = -1;
            } else if(dy == -1){
                dx = -1;
                dy = 0;
            } else if(dx == -1){
                dx = 0;
                dy = 1;
            } else {
                dx = 1;
                dy = 0;
            }
        }
    }

    cout << x << " " << y << endl;
}