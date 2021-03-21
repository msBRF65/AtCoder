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
    double a, b, w;
    cin >> a >> b >> w;
    w *= 1000;

    ll min = ceil(w / b);
    ll max = floor(w / a);

    if(min > max || max <= 0) {
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }
    cout << min << " " << max << endl;
    return 0;
}