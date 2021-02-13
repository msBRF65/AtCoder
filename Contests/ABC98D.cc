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
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<int> a(n);
    loop(i,n) cin >> a[i];

    vector<int> bit_sum_init(20,0);
    vector<vector<int>> bit_sum(n, bit_sum_init);

    loop(i,n){
        loop(j,20){
            if(i == 0) bit_sum[i][j] = (a[i] >> j) % 2;
            else bit_sum[i][j] = bit_sum[i - 1][j] + (a[i] >> j) % 2;
        }
    }

    ll r = 1;
    ll ans = 0;
    loop(i,n){
        r = max(r, i + 1);

        while(1){
            if(r >= n) break;
            ll num = 0;
            loop(j, 20){
                if(i == 0) {
                    if(bit_sum[r][j] > 1) num ++; 
                }
                else if(bit_sum[r][j] - bit_sum[i - 1][j] > 1) num ++;
            }
            if(num == 0) r++;
            else break;
        }
        ans += (r - i);
    }

    cout << ans << endl;
}