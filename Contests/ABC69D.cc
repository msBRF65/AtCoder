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

int main(){
    ll h, w, n;
    cin >> h >> w;
    cin >> n;

    vector<ll> a(n);
    
    loop(i, n){
        cin >> a[i];
    }

    vector<vector<ll>> hw(h);

    ll total_num = 0;
    loop(i, n){
        loop(j, a[i]){
            hw[total_num / w].push_back(i + 1);
            total_num ++;
        }
    }

    loop(i, h){
        if(i % 2 == 0) loop(j, w) cout << hw[i][j] << " ";
        else loop(j, w) cout << hw[i][w - 1 - j] << " ";
        cout << endl;
    }
}