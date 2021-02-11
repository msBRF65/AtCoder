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

struct edge {
    int parent;
    int children;
    int distance;
};

struct node{
    int color = 0;
    bool isSearched = false;
    vector<edge> e;
};

edge revE(edge e){
    edge tmpE;
    tmpE.children = e.parent;
    tmpE.parent = e.children;
    tmpE.distance = e.distance;
    return tmpE;
}

int main(){
    int n;
    cin >> n;

    vector<node> nodes(n+1);

    queue<int> q;

    loop(i,n-1){
        edge tmpE;
        cin >> tmpE.parent >> tmpE.children >> tmpE.distance;

        nodes[tmpE.parent].e.push_back(tmpE);
        tmpE = revE(tmpE);
        nodes[tmpE.parent].e.push_back(tmpE);
    }

    q.push(1);

    while(!q.empty()){
        node tmpN = nodes[q.front()];
        q.pop();

        loop(i,tmpN.e.size()){
            edge tmpE = tmpN.e[i];

            nodes[tmpE.children].color = nodes[tmpE.parent].color ^ tmpE.distance % 2;

            if(! nodes[tmpE.children].isSearched){
                nodes[tmpE.children].isSearched = true;
                q.push(tmpE.children);
            }
        }
    }

    loop(i,n){
        cout << nodes[i+1].color << endl;
    }

    return 0;
}
