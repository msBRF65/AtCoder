#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//Single Source Shortest Path1:https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
//Bellman-Ford法で解く
//中央奥
//updateしなかった場合にbreakしないコードだとTLEになってしまった

const int inf = -1;

int main(){
    int V,E,r,s,t,d;
    bool update;
    cin >> V >> E >> r;
    vector<int> a(3,0), Score(V,inf);
    vector<vector<int> > Edges(E,a);
    for(int i = 0; i < E;i++){
        cin >> Edges[i][0] >> Edges[i][1] >> Edges[i][2];
    }
    Score[r] = 0;
    for(int i = 0;i < V-1;i++){
        update = false;
        for(int k = 0;k < E;k++){
            if(Score[Edges[k][0]] != -1){
                if(Score[Edges[k][1]] > Score[Edges[k][0]] + Edges[k][2] || Score[Edges[k][1]] == -1){
                    Score[Edges[k][1]] = Score[Edges[k][0]] + Edges[k][2];
                    update = true;
                }
            }
        }
        if(!update)break;
    }
    for(int i = 0;i < V;i++){
        if(Score[i] == -1){
            cout << "INF" << endl;
        }
        else cout << Score[i] << endl;
    }
}