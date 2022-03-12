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
        bool is_same_left = q_left == range_left;
        bool is_same_right = q_right == range_right;
        if (is_same_left && is_same_right)
        {
            return vec[pow(2, depth) + leaf_id_in_layer];
        }

        bool use_left_leaf = q_left <= range_left + range_leaf / 2 - 1;
        bool use_right_leaf = q_right >= range_left + range_leaf / 2;
        ll ans = 0;
        if (use_left_leaf)
        {
            ans += get(range_left, range_left + range_leaf / 2 - 1, depth + 1, leaf_id_in_layer * 2);
        }
        if (use_right_leaf)
        {
            ans += get(range_left + range_leaf / 2, range_right, depth + 1, leaf_id_in_layer * 2 + 1);
        }
        return ans;
    }

    ll add(ll id)
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

int main()
{
    ll n;
    cin >> n;

    vector<P> items(n);
    loop(i,n){
        cin >> items[i].first;
    }
    loop(i,n){
        cin >> items[i].second;
    }

    sort(items.begin(), items.end());

    ll ans = 0;
    SegmentTree st(1000000001);
    loop(i,n){
        ans += st.get(items[i].second, 1000000000);
        st.add(items[i].second);
    }
    cout << ans + n << endl;
}