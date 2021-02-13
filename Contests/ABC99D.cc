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
    ll n, c;
    cin >> n >> c;

    vector<ll> color[3];
    vector<vector<ll>> wrongness(c);

    loop(i,c){
        loop(j,c){
            ll tmp_w;
            cin >> tmp_w;
            tmp_w;
            wrongness[i].push_back(tmp_w);
        }
    }

    loop(i,n){
        loop(j,n){
            ll tmp_c;
            cin >> tmp_c;
            tmp_c --;
            color[(i+j+2) % 3].push_back(tmp_c);
        }
    }

    vector<P> score_after_paint[3];

    loop(i,3){
        loop(j, c){
            ll score = 0;
            for(ll k: color[i]){
                score += wrongness[k][j];
            }
            score_after_paint[i].emplace_back(score, j);
        }
        sort(score_after_paint[i].begin(), score_after_paint[i].end());
    }

    vector<ll> ans;

    loop(i,3){
        loop(j,3){
            loop(k,3){
                if(score_after_paint[0][i].second == score_after_paint[1][j].second) continue;
                if(score_after_paint[1][j].second == score_after_paint[2][k].second) continue;
                if(score_after_paint[2][k].second == score_after_paint[0][i].second) continue;

                ans.push_back(score_after_paint[0][i].first + score_after_paint[1][j].first + score_after_paint[2][k].first);
            }
        }
    }

    sort(ans.begin(), ans.end());
    
    cout << ans[0] << endl;
}