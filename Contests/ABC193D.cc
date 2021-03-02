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
    ll k;
    string s,t;
    cin >> k >> s >> t;

    ll takahashi[9] = {0};
    ll aoki[9] = {0};

    loop(i,4) takahashi[s[i] - '0' - 1] ++;
    loop(i,4) aoki[t[i] - '0' - 1] ++;

    ll ans = 0;
    ll total = 0;
    loop(i,9){
        loop(j,9){
            ll p;
            if(i == j && 2 + takahashi[i] + aoki[j] > k) continue; 
            else if(1 + takahashi[i] + aoki[i] > k) continue;
            else if(1 + takahashi[j] + aoki[j] > k) continue;

            ll takahashi_score = 0;
            ll aoki_score = 0;
            loop(k,9){
                ll tmp = takahashi[k];
                if(k == i) tmp ++;
                takahashi_score += ll(pow(10, tmp)) * (k + 1);
            }
            loop(k,9){
                ll tmp = aoki[k];
                if(k == j) tmp ++;
                aoki_score += ll(pow(10, tmp)) * (k + 1);
            }
            if(i == j) {
                ll r = k - takahashi[i] - aoki[j];
                p = r * (r - 1); 
            } else {
                p = (k - takahashi[i] - aoki[i]) * (k - takahashi[j] - aoki[j]);
            }
            if(takahashi_score > aoki_score) ans += p;
            total += p;
        }
    }

    cout << double(ans) / total << endl;
}