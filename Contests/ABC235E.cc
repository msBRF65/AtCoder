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
    ll query_num;

    Edge(){}
    Edge(ll from, ll to, ll weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->query_num = -1;
    }
    Edge(ll from, ll to, ll weight, ll query_num)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->query_num = query_num;
    }

    bool is_query_edge()
    {
        return query_num != -1;
    }
};

struct UnionFind
{
    vector<int> parent;

    UnionFind(int N) : parent(N)
    {
        loop(i, N) parent[i] = i;
    }

    int root(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        parent[rx] = ry;
        return;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edge_vec(m + q);
    vector<bool> ans(q);

    loop(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edge_vec[i] = Edge(a - 1, b - 1, c);
    }

    loop(i, q)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edge_vec[i + m] = Edge(u - 1, v - 1, w, i);
    }

    sort(edge_vec.begin(), edge_vec.end(), [](const Edge &left, const Edge &right)
         { return left.weight < right.weight; });
    

    UnionFind uf(n);
    for (Edge tmp_edge : edge_vec)
    {
        // cout << tmp_edge.from << " " << tmp_edge.to << " " << tmp_edge.weight << endl;
        if (tmp_edge.is_query_edge())
        {
            ans[tmp_edge.query_num] = !uf.same(tmp_edge.from, tmp_edge.to);
        }
        else
        {
            uf.unite(tmp_edge.from, tmp_edge.to);
        }
    }

    loop(i, q)
    {
        if (ans[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}