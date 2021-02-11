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
    ll n, m;
    cin >> n >> m;

    vector<P> range;

    loop(i,m){
        ll a, b;
        cin >> a >> b;

        a --;
        b -= 2;
        range.emplace_back(a,b);
    }
    
    sort(range.begin(), range.end());

    auto has_same_bridge = [&](P a, P b){
        if(a.second < b.first) return false;
        else return true;
    };

    vector<P> ans;
    ans.push_back(range[0]);

    for(int i = 1; i < m; i++){
        if(has_same_bridge(ans[ans.size() - 1], range[i])){
            ans[ans.size() - 1].first = range[i].first;
            ans[ans.size() - 1].second = min(ans[ans.size() - 1].second, range[i].second);
        }else{
            ans.push_back(range[i]);
        } 
    }

    cout << ans.size() << endl;
}