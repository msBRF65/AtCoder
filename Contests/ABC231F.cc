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

class SegmentTree
{
private:
    ll num_end_leaves;
    ll tree_depth;
    vector<ll> vec;

public:
    SegmentTree(ll n)
    {
        num_end_leaves = 1;
        tree_depth = 0;
        while (num_end_leaves < n)
        {
            num_end_leaves *= 2;
            tree_depth++;
        }
        vec.resize(num_end_leaves * 2, 0);
    }

    ll get(ll q_left, ll q_right, ll depth = 0, ll leaf_id_in_layer = 0)
    {
        ll range_leaf = pow(2, tree_depth - depth);
        ll range_left = range_leaf * leaf_id_in_layer;
        ll range_right = range_left + range_leaf - 1;
        bool is_same_left = (q_left == range_left);
        bool is_same_right = (q_right == range_right);
        if (is_same_left && is_same_right)
        {
            return vec[pow(2, depth) + leaf_id_in_layer];
        }

        bool use_left_leaf = q_left <= (range_left + range_leaf / 2 - 1);
        bool use_right_leaf = q_right >= (range_left + range_leaf / 2);
        ll ans = 0;
        if (use_left_leaf)
        {
            ans += get(q_left, min(range_left + range_leaf / 2 - 1, range_right), depth + 1, leaf_id_in_layer * 2);
        }
        if (use_right_leaf)
        {
            ans += get(max(range_left + range_leaf / 2, q_left), q_right, depth + 1, leaf_id_in_layer * 2 + 1);
        }

        return ans;
    }

    void add(ll id)
    {
        ll array_id = id + num_end_leaves;
        vec[array_id]++;
        while (array_id > 0)
        {
            array_id /= 2;
            vec[array_id] = vec[array_id * 2] + vec[array_id * 2 + 1];
        }
    }
};

void comp(vector<ll> &a)
{
    set<ll> s(a.begin(), a.end());
    map<ll, ll> m;

    int cnt = 0;
    for (auto x : s)
        m[x] = cnt++;
    for (auto &x : a)
        x = m[x];
};

int main()
{
    ll n;
    cin >> n;

    vector<P> items(n);
    vector<ll> a(n), b(n);
    loop(i, n)
    {
        cin >> a[i];
    }
    loop(i, n)
    {
        cin >> b[i];
    }

    comp(a);
    comp(b);
    loop(i, n)
    {
        items[i].first = a[i];
        items[i].second = b[i];
    }

    sort(items.begin(), items.end(), [](P a, P b)
         {
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first; });

    ll ans = 0;
    SegmentTree st(200000);
    loop(i, n)
    {
        ll item_num = st.get(items[i].second, 199999);
        ans += item_num;
        st.add(items[i].second);
    }

    loop(i, n)
    {
        ll cnt = 1;
        while (i + 1 < n && items[i] == items[i + 1])
        {
            cnt++;
            i++;
        }
        ans += cnt * (cnt + 1) / 2;
    }
    cout << ans << endl;
}