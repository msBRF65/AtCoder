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

struct Edge {
    ll size;
    ll id;
    vector<ll> crossed_edge;
};

bool compare(Edge l , Edge r){
    return l.size <= r.size;
}

bool id_sort(Edge l , Edge r){
     return l.id <= r.id;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    vector<Edge> edges(m);
    loop(i,m) edges[i].id = i;
    loop(i, m)
    {
        cin >> a[i] >> b[i];
    }
    loop(i, m - 1)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (a[i] == a[j] || b[i] == b[j])
            {
                edges[i].crossed_edge.push_back(j);
                edges[j].crossed_edge.push_back(i);
            }else if((a[i] < a[j]) != (b[i] < b[j])){
                edges[i].crossed_edge.push_back(j);
                edges[j].crossed_edge.push_back(i);
            }
        }
    }

    loop(i,m) edges[i].size = edges[i].crossed_edge.size();
    
    ll ans = 0;
    vector<bool> is_searched(m,false);
    sort(edges.begin(), edges.end(), compare);
    loop(i,m){
        ll tmp_id = edges[i].id; 
        if(is_searched[tmp_id] == false){
            is_searched[tmp_id] = true;
            ans ++;
            for(ll j: edges[i].crossed_edge){
                is_searched[j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}