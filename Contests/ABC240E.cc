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

struct Node
{
    int id = -1;
    vector<Node *> child;
    int l = 1000000;
    int r = -1;
    bool have_area = false;

    void SetId(int id)
    {
        this->id = id;
        this->l = id;
        this->r = id;
        return;
    }

    void SetChild(Node *node)
    {
        this->child.push_back(node);
        return;
    }

    void UpdateArea()
    {
        if (this->child.size() == 0)
        {
            this->l = this->id;
            this->r = this->id;
            this->have_area = true;
            return;
        }

        loop(i, ll(this->child.size()))
        {
            if (!this->child[i]->have_area)
            {
                this->child[i]->UpdateArea();
            }
            this->l = min(this->child[i]->l, this->l);
            this->r = max(this->child[i]->r, this->r);
        }
        this->have_area = true;
        return;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Node> node_vec(n);
    vector<vector<int>> edge(n);
    vector<bool> is_searched(n, false);

    loop(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        edge[u - 1].push_back(v - 1);
        edge[v - 1].push_back(u - 1);
    }

    queue<int> q;
    q.push(0);

    int id = 1;
    while (!q.empty())
    {
        ll node_id = q.front();
        q.pop();

        is_searched[node_id] = true;

        int child_num = 0;

        for (int child_id : edge[node_id])
        {
            if (!is_searched[child_id])
            {
                q.push(child_id);
                node_vec[node_id].SetChild(&node_vec[child_id]);
                child_num++;
            }
        }

        if (child_num == 0)
        {
            node_vec[node_id].SetId(id);
            id++;
        }
    }

    node_vec[0].UpdateArea();

    loop(i, n)
    {
        cout << node_vec[i].l << " " << node_vec[i].r << endl;
    }

    return 0;
}