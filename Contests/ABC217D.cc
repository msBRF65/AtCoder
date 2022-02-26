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
    int start;
    int end;
    bool has_children;
    int children[2];
    int cut_pos;

    Node():start{0}, end{0}, has_children{false}{};
    Node(int s, int e) : start{s}, end{e}, has_children{false} {};
};

Node node_array[400000];

int find_Node(int root, int pos)
{
    Node tmp = node_array[root];
    if (!(tmp.has_children))
        return root;
    if (pos < tmp.cut_pos)
    {
        return find_Node(tmp.children[0], pos);
    }
    else
        return find_Node(tmp.children[1], pos);
}

int main()
{
    int l, q;
    cin >> l >> q;

    Node root(0, l);
    node_array[0] = root;
    int next_id = 1;
    vector<int> ans_array;
    loop(i, q)
    {
        int c, x;
        cin >> c >> x;
        int tmp_id = find_Node(0, x);
        if(c == 1){
            node_array[tmp_id].cut_pos = x;
            node_array[tmp_id].has_children = true;
            node_array[tmp_id].children[0] = next_id;
            node_array[tmp_id].children[1] = next_id + 1;
            Node a = Node(node_array[tmp_id].start, x);
            Node b = Node(x, node_array[tmp_id].end);
            node_array[next_id] = a;
            node_array[next_id + 1] = b; 
            next_id += 2;
        } else {
            int tmp_ans = node_array[tmp_id].end - node_array[tmp_id].start;
            ans_array.push_back(tmp_ans);
        }
    }

    loop(i,ans_array.size()){
        cout << ans_array[i] << endl;
    }

    return 0;
}