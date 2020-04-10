#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int inf = 100000000;

//A Reward for a Carpenter:https://onlinejudge.u-aizu.ac.jp/problems/0117
//中央奥
//文字がたくさん出てきて混乱した。文字に意味を持たせるべきだったかもしれない

int main(){
    int n,m,s,g,V,P,K[210][210],a,b,c,d;
    cin >> n >> m;
    for(int i = 0;i < 210;i++){
        for(int j = 0;j < 210;j++){
            K[i][j] = inf;
        }
    }
    for(int i = 0;i < m;i++){
        scanf("%d,%d,%d,%d",&a,&b,&c,&d);
        K[a][b] = c;
        K[b][a] = d;
    }
    scanf("%d,%d,%d,%d",&s,&g,&V,&P);
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(K[i][j] > K[i][k] + K[k][j]){
                    K[i][j] =  K[i][k] + K[k][j];
                }
            }
        }
    }
    cout << V-P-K[s][g]-K[g][s] << endl;
}