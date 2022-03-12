#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <deque>
#include <map>
#include <queue>
#include <cmath>
#include <set>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n)        \
    for (ll i = 0; i < n; i++) \
    {                          \
        cout << a[i] << ' ';   \
    }                          \
    cout << endl;
#define inf 100000000000
#define loop(i, n) for (ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll, ll>

using namespace std;

struct Edge
{
    ll from;
    ll to;
    ll weight;
    Edge(ll from, ll to, ll weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

ll dist[300][300] = {inf};

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<Edge> edge_vec;

    loop(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge_vec.push_back(Edge(a, b, c));
        dist[a][b] = c;
        dist[b][a] = c;
    }

    loop(i, n)
    {
        loop(j, n)
        {
            loop(k, n)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = 0;
    loop(i,m){
        bool tmp_ans = false;
        loop(j,n){
            Edge tmp_e = edge_vec[i];
            if(j == tmp_e.from || j == tmp_e.to) continue;
            if(tmp_e.weight >= dist[tmp_e.from][j] + dist[j][tmp_e.to]){
                tmp_ans |= true;
            }
        }
        ans += tmp_ans;
    }

    cout << ans << endl;
}