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

const int node_num = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
vector<int> edge_vec[9];
int is_searched[node_num];

int main(){
    int m;
    cin >> m;
    loop(i,m){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        edge_vec[u].push_back(v);
        edge_vec[v].push_back(u);
    }

    int p;
    string s = "999999999";
    loop(i,8){
        cin >> p;
        s[p-1] = i + 1 + '0';
    }

    if(s == "123456789") {
        cout << 0 << endl;
        return 0;
    }

    map<string, int> mp;
    queue<string> q;
    q.push(s);
    mp[s] = 0;


    while(q.size()){
        string s = q.front();
        q.pop();
        // cout << s << endl;

        int u;
        loop(i,9){
            if(s[i] == '9') u = i;
        }

        for(int v: edge_vec[u]){
            string new_s = s;
            char tmp = new_s[u];
            new_s[u] = new_s[v];
            new_s[v] = tmp;

            if(new_s == "123456789"){
                cout << mp[s] + 1 << endl;
                return 0;
            }

            if(mp.count(new_s) == 0){
                mp[new_s] = mp[s] + 1;
                q.push(new_s);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}