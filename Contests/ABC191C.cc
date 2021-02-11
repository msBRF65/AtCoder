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
    ll h,w;
    cin >> h >> w;

    vector<vector<int>> s(h);

    loop(i,h){
        loop(j,w){
            char c;
            cin >> c;
            if(c == '#') {
                s[i].push_back(1);
            }else{
                s[i].push_back(0);
            }
        }
    }

    ll ans = 0;

    loop(i, h - 1){
        loop(j, w - 1){
            int tmp = s[i][j] + s[i + 1][j] + s[i][j + 1] + s[i + 1][j + 1]; 
            if(tmp == 1 || tmp == 3) ans++;
        }
    }

    cout << ans << endl;
}