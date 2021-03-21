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
#define loop(i,nn) for(ll i = 0; i < nn; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

bool compare(P l, P r){
    if(l.first == r.first) return l.second < r.second;
    return l.first > r.first;
};

int main(){
    ll n, m, q;
    cin >> n >> m >> q;
    
    vector<P> items(n);
    vector<ll> boxes(m);
    vector<P> query(q);

    loop(i,n) cin >> items[i].second >> items[i].first;

    sort(items.begin(), items.end(), compare);

    loop(i,m) {
        cin >> boxes[i];
    }

    loop(i,q) {
        cin >> query[i].first >> query[i].second;
    }

    loop(i,q){
        ll l, r;
        vector<P> available_box;

        l = query[i].first - 1;
        r = query[i].second - 1;

        loop(j,m){
            if(l <= j && j <= r) continue;
            available_box.emplace_back(boxes[j], 0);
        }
        sort(available_box.begin(), available_box.end());

        ll ans = 0;
        loop(k, ll(items.size())){
            P item = items[k];
            loop(j, ll(available_box.size())){
                P box = available_box[j];
                if(box.second == 0 && item.second <= box.first){
                    ans += item.first;
                    available_box[j].second = 1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}