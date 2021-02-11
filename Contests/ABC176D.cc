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
    ll h, w;
    cin >> h >> w;

    ll ch, cw;
    ll dh, dw;

    cin >> ch >> cw;
    ch --; cw --;
    cin >> dh >> dw;
    dh --; dw --;

    vector<vector<bool>> is_road(h);
    vector<ll> cost(h * w, -1);

    loop(i,h){
        loop(j,w){
            char s;
            cin >> s;
            if(s == '#') is_road[i].push_back(false);
            else is_road[i].push_back(true);
        }
    }

    queue<P> q;

    cost[ch * w + cw] = 0;
    q.push(P(0, ch * w + cw));

    auto update_cost = [&](ll hh, ll ww, ll cc){
        if(cost[hh * w + ww] != -1 || !is_road[hh][ww]) return;
        cost[hh * w + ww] = cc;
        q.push(P(cc, hh * w + ww));
        return;
    };

    while(!q.empty()){
        vector<ll> same_area;
        while(!q.empty()){
            P tmp = q.front();
            q.pop();
            same_area.push_back(tmp.second);

            ll tmp_h = tmp.second / w;
            ll tmp_w = tmp.second % w;

            if(tmp_h - 1 >= 0) update_cost(tmp_h - 1, tmp_w, tmp.first);
            if(tmp_h + 1 < h) update_cost(tmp_h + 1, tmp_w, tmp.first);
            if(tmp_w - 1 >= 0) update_cost(tmp_h, tmp_w - 1, tmp.first);
            if(tmp_w + 1 < w) update_cost(tmp_h, tmp_w + 1, tmp.first);
        }

        for(ll i :same_area) {
            for(int j = -2; j <= 2; j++){
                for(int k = -2; k <= 2; k++){
                    if(0 <= i / w + j && i / w + j < h && 0 <= i % w + k && i % w + k < w){
                        if(is_road[i / w + j][i % w + k] && cost[i + j * w + k] == -1){    
                            q.push(P(cost[i] + 1, i + j * w + k));
                            cost[i + j * w + k] = cost[i] + 1;
                        }
                    }
                }
            }
        }

    }

    cout << cost[dh * w + dw] << endl;
}