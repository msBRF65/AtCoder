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
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct Node {
    ll num;
    vector<ll> connected_node = {0};
    bool is_searched = false;
    ll sign = -1;
};

int main(){
    ll n,m;
    cin >> n >> m;

    vector<Node> g(n);

    loop(i,n){
        g[i].num = i;
    }

    loop(i, m){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        g[tmp1-1].connected_node.push_back(tmp2-1);
        g[tmp2-1].connected_node.push_back(tmp1-1);
    }

    queue<ll> q;
    g[0].is_searched = true;
    g[0].sign = 1;

    loop(i, g[0].connected_node.size()){
        ll node_num = g[0].connected_node[i];
        q.push(node_num);
        g[node_num].sign = 0;
        g[node_num].is_searched = true;
     }

    while(!q.empty()){
        ll node_num = q.front();
        q.pop();

        loop(i, g[node_num].connected_node.size()){
            ll connected_node_num = g[node_num].connected_node[i];

            if(!g[connected_node_num].is_searched){
                q.push(connected_node_num);
                g[connected_node_num].sign = node_num;
                g[connected_node_num].is_searched = true;
            }
        }
    }

    loop(i,n){
        if(g[i].is_searched == false) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    loop(i,n-1){
        cout << g[i+1].sign + 1<< endl;
    }

    return 0;
}