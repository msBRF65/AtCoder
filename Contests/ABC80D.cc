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
    ll n,c;
    cin >> n >> c;

    vector<vector<P>> channel(c);

    loop(i,n){
        ll s,t,c;
        cin >> s >> t >> c;
        channel[c - 1].emplace_back(s,t);
    }
    
    vector<P> range;
    loop(i,c){
        vector<P> tmp; 
        sort(channel[i].begin(), channel[i].end());

        for(P r: channel[i]){
            if(tmp.size() > 0 && tmp[tmp.size() - 1].second == r.first){
                tmp[tmp.size() - 1].second = r.second;
            } else {
                tmp.push_back(r);
            }
        }

        for(P r: tmp) range.push_back(r);
    }

    vector<ll> diff(100020, 0);

    for(P r: range){
        diff[r.first - 1] ++;
        diff[r.second] --;
    }

    ll ans = 0;
    ll tmp = 0;
    for(ll i:diff){
        tmp += i;
        ans = max(tmp, ans);
    }

    cout << ans << endl;
}