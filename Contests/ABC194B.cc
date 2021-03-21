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
    vector<P> jobs(n);

    loop(i,n){
        cin >> jobs[i].first >> jobs[i].second;
    }

    ll ans = inf;
    loop(i,n){
        loop(j,n){
            if(i == j) ans = min(jobs[i].first + jobs[j].second, ans);
            else ans = min(max(jobs[i].first, jobs[j].second), ans);
        }
    }

    cout << ans << endl;
    return 0;
    
}