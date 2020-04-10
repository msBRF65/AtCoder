#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
//BreadthFirstSearch:https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C
//Queueの使い方を学んだ

int main(){
   int n,u,v,k,inf = -1;
   cin >> n;
   vector<int> a(n,0),D(n,inf);
   vector<vector<int> > edges(n,a); 
   for(int i = 0;i < n;i++){
       cin >> u;
       cin >> v;
       for(int ii = 0;ii < v;ii++){
           cin >> k;
           edges[u-1][k-1] = 1;
       }
   }
   queue<int> Q;
   Q.push(0);
   D[0] = 0;
   while(!Q.empty()){
        int cur = Q.front();
        Q.pop();//最初の要素を削除、詰める
        for(int dst = 0;dst < n;dst++){
            if(edges[cur][dst] == 1 && D[dst] == inf){
                D[dst] = D[cur] + 1;
                Q.push(dst);
            }
        }
   }
   for(int i = 0;i < n;i++){
       cout << i+1 << " " << D[i] << endl;
   }
}