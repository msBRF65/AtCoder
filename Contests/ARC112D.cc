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
    ll h,w;
    cin >> h >> w;

    vector<vector<bool>> is_ground(h);
    vector<vector<ll>> edge(h+w);

    loop(i,h){
        loop(j,w){
            char c;
            cin >> c;
            if((i == 0 || i == h - 1) && (j == 0 || j == w - 1)){
                is_ground[i].push_back(true);
            } else {
                if(c == '#') is_ground[i].push_back(true);
                else is_ground[i].push_back(false);
            }
        }
    }

    loop(i,h){
        loop(j,w){
            if(is_ground[i][j]){
                edge[i].push_back(h + j);
                edge[h + j].push_back(i);
            }
        }
    }

    vector<ll> is_searched(h + w, -1); 
    ll group_num = 0;
    ll next_v = 0;
    while(1){
        bool is_finished = false;
        for(int i = next_v; i < h + w; i++){
            if(is_searched[i] == -1){
                next_v = i;
                break;
            }
            if(i == h + w - 1) is_finished = true;
        }

        if(is_finished) break;

        group_num ++;

        queue<ll> q;
        q.push(next_v);
        is_searched[next_v] = group_num;

        while(!q.empty()){
            ll v = q.front();
            q.pop();

            for(ll e: edge[v]){
                if(is_searched[e] == -1){
                    is_searched[e] = group_num;
                    q.push(e);
                }
            }
        }   
    }

    ll h_ans = -1;
    set<ll> s_h;
    loop(i,h){
        s_h.insert(is_searched[i]);
    }
    set<ll> s_w;
    loop(i,w){
        s_w.insert(is_searched[h + i]);
    }

    cout << min(s_h.size(), s_w.size()) - 1 << endl;
}