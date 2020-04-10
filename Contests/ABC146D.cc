#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(int i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(int i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct Edge{
    int to,id;
};

int main(){
    ll n;
    cin >>n;

    vector<vector<Edge>> edgeVector(n);
    vector<int> ans(n-1);
    loop(i,n-1){
        int a,b;
        cin >>a >>b;
        a--;
        b--;
        edgeVector[a].push_back(Edge{b,i});
        edgeVector[b].push_back(Edge{a,i});
    }

    vector<int> used(n,0);
    queue<int> q;
    q.push(0);
    used[0] = 1;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        int c = -1;
        loop(i, edgeVector[current].size()){
            int to = edgeVector[current][i].to;
            int id = edgeVector[current][i].id;
            
            if(used[to]) c = ans[id];
        }

        int k = 1;
        loop(i, edgeVector[current].size()){
            int to = edgeVector[current][i].to;
            int id = edgeVector[current][i].id;

            if(used[to]) continue;
            if(k == c) k++;
            ans[id] = k;
            k++;
            q.push(to);
            used[to] = 1;
        }
    }

    int maxValue = 0;
    loop(i,n-1){
        maxValue = max(ans[i],maxValue);
    }
    cout << maxValue << endl;

    loop(i, n-1){
        cout << ans[i] << endl;
    }

    return 0;

}