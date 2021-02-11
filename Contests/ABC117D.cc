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
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    loop(i,n) cin >> a[i];

    sort(a.begin(),a.end());

    bool isLessThanK = false;
    ll result = 0;

    for(int i = 39; i >= 0; i--){
        // kより大きくなるかも→桁が0なら0,1なら比較
        // kより絶対に小さい→0と1を選べる
        if(isLessThanK){
            int count = 0;
            loop(j,n){
                count += a[j] >> i & 1;
            }
            if(count * 2 > n){
                result <<= 1;
                result += count;
            }else{
                result <<= 1;
                result += n - count;
            }
        }else{
            int count = 0;
            loop(j,n){
                count += a[j] >> i & 1;
            }
            if(k >> i & 1){
                if(count * 2 > n){
                    result <<= 1;
                    result += count;
                    isLessThanK = true;
                }else{
                    result <<= 1;
                    result += n - count;
                }
            }else{
                result <<= 1;
                result += count;
            }
        }
    }
    cout << result << endl;
}