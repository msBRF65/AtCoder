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

int l[2000][2000],r[2000][2000],a[2000][2000],u[2000][2000];
bool isWall[2000][2000];

int main(){
    int h,w;
    char tmp;

    cin >> h >> w;

    scanf("%c",&tmp);
    loop(i,h){
        loop(j,w){
            scanf("%c",&tmp);
            if(tmp == '.'){
                isWall[i][j] = false;
            }else{
                isWall[i][j] = true;
            }
        }
        scanf("%c",&tmp);
    }

    loop(i,h){
        loop(j,w){
            if(isWall[i][j]){
                l[i][j] = 0;
                a[i][j] = 0;
            }
            else{
                if(j != 0){
                    l[i][j] = l[i][j-1] + 1;
                }else{
                    l[i][0] = 1;
                }
                if(i != 0){
                    a[i][j] = a[i-1][j] + 1;
                }else{
                    a[0][j] = 1;
                }
            }
        }
    }

    for(int i = h-1; i >= 0; i--){
        for(int j = w-1; j >= 0; j--){
            if(isWall[i][j]){
                r[i][j] = 0;
                u[i][j] = 0;
            }
            else{
                if(j != w-1){
                    r[i][j] = r[i][j+1] + 1;
                }else{
                    r[i][w-1] = 1;
                }
                if(i != h-1){
                    u[i][j] = u[i+1][j] + 1;
                }else{
                    u[i][j] = 1;
                }
            }
        }
    }

    int result = 0, score;
    loop(i,h){
        loop(j,w){
            score = l[i][j] + r[i][j] + a[i][j] + u[i][j];
            result = max(score, result);
        }
    }

    cout << result - 3 << endl;
    return 0;
}