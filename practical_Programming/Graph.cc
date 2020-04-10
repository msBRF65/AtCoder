#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//Graph:https://onlinejudge.u-aizu.ac.jp/#/problems/ALDS1_11_A
//Vectorの使い方を学んだ,PEが初めて出た
//中央奥

int main(){
   int n,u,v,k;
   cin >> n;
   vector<int> a(n,0);
   vector<vector<int> > edges(n,a); 
   for(int i = 0;i < n;i++){
       cin >> u;
       cin >> v;
       for(int ii = 0;ii < v;ii++){
           cin >> k;
           edges[u-1][k-1] = 1;
       }
   }
   for(int i = 0;i < n;i++){
       for(int ii = 0;ii < n;ii++){
           if(ii == n-1){
               cout << edges[i][ii];
           }
           else{
               cout << edges[i][ii] << " ";
           }
       }
       cout <<"\n";
   }
}