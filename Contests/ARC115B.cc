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

    vector<vector<ll>> c(n);
    loop(i,n){
        loop(j,n){
            ll cc;
            cin >> cc;
            c[i].push_back(cc);
        }
    }

    vector<ll> a(n), b(n);
    a[0] = c[0][0];
    b[0] = 0;
    for(ll i = 1; i < n; i++){
        a[i] = c[i][0] - b[0];
        b[i] = c[0][i] - a[0];
    }

    loop(i,n){
        loop(j,n){
            if(a[i] + b[j] != c[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    ll min_a = inf, min_b = inf;
    loop(i,n){
        min_a = min(min_a, a[i]);
        min_b = min(min_b, b[i]);
    }

    // debug_arr(a, n);
    // debug_arr(b, n);

    // debug(min_a);
    // debug(min_b);

    if(min_a + min_b < 0){
        cout << "No" << endl;
        return 0;
    }

    ll diff_a = 0, diff_b = 0;
    if(min_a < 0 || min_b < 0){
        if(min_a < 0) {
            diff_b = min_a;
            diff_a = -1 * min_a;
        } else {
            diff_a = min_b;
            diff_b = -1 * min_b;
        }
    }

    // debug(diff_a);
    // debug(diff_b);

    cout << "Yes" << endl;
    loop(i,n) cout << a[i] + diff_a << " ";
    cout << endl;
    loop(i,n) cout << b[i] + diff_b << " ";
    cout << endl;

    return 0;
}