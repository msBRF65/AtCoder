#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)

using namespace std;

struct UnionFind{
    vector<int> parent;

    UnionFind(int N): parent(N){
        loop(i, N) parent[i] = i;
    }

    int root(int x){
        if(parent[x] == x)return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        parent[rx]= ry;
        return;
    }

    bool same(int x,int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    int n,m,k,a,b,c,d;
    cin >>n >>m >>k;

    vector<int> blockFriend(n,0),groupMember(n,0), FriendNum(n,0);
    UnionFind tree(n);
    loop(i, m){
        cin >>a >>b;
        tree.unite(a-1,b-1);
        FriendNum[a-1] ++;
        FriendNum[b-1] ++;
    }
    
    loop(i,n){
        int ri = tree.root(i);
        groupMember[ri] ++;
    }

    loop(i, k){
        cin >>c >>d;
        if(tree.same(c-1,d-1)){
            blockFriend[c-1]++; 
            blockFriend[d-1]++;
        }
    }

    loop(i,n){
        int ri = tree.root(i);
        cout << groupMember[ri] - blockFriend[i] - FriendNum[i] - 1 << endl;
    }

    return 0;

}