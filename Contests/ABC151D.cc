#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll h,w;
    cin >>h >>w;

    vector<string> str(h);
    
    loop(i,h) cin >>str[i];

    ll ans = 0;

    ll di[4] = {-1, 0, 1, 0};
    ll dj[4] = {0, 1, 0, -1};
    
    loop(i,h){
        loop(j,w){
            if(str[i][j] == '#') continue;
            graph node(h, vector<ll>(w,inf));

            queue<P> q;

            auto update = [&](ll i, ll j, ll x){
                if(node[i][j] != inf) return;
                node[i][j] = x;
                q.push(P(i,j));
            };

            update(i,j,0);

            while(!q.empty()){
                P ij = q.front();
                q.pop();
                loop(k,4){
                    ll ii = ij.first + di[k];
                    ll jj = ij.second + dj[k];
                    if(ii < 0 || ii >= h || jj < 0 || jj >= w) continue;
                    if(str[ii][jj] == '#') continue;
                    
                    update(ii,jj,node[ij.first][ij.second]+1);
                };                
            }

            loop(si,h){
                loop(sj,w){
                    if(node[si][sj] == inf)continue;
                    ans = max(ans, node[si][sj]);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;

}
