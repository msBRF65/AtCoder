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

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

vector<ll> toNodeIndex[200005];
vector<ll> counter;

void bfs(ll root, ll from = -1){
    vector<ll> childNodes;
    ll thisCounter = counter[root];
    childNodes = toNodeIndex[root];

    if(childNodes.size() == 0)return;

    for(ll childNodeIndex :childNodes){
        if(childNodeIndex == from) continue;

        counter[childNodeIndex] += thisCounter;

        bfs(childNodeIndex, root);
    }

    return;
}

int main(){
    ll n,q;
    cin >>n >>q;

    loop(i,n-1){
        ll a,b;
        cin >>a >>b;
        --a; --b;

        toNodeIndex[a].push_back(b);
        toNodeIndex[b].push_back(a);
    }

    counter.resize(n);

    loop(i,q){
        ll p,x;
        cin >>p >>x;
        p--;
        counter[p] += x;
    }

    bfs(0);

    loop(i,n){
        cout << counter[i] << endl;
    }

    return 0;
}