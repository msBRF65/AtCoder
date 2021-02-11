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

int mod = 1000000007;
struct acgt{
    int ans[4][4][4]={{{0}}};

    int sum(){
        int result = 0;
        loop(i,4){
            loop(j,4){
                loop(k,4){
                    if(i == 2 && j == 0 && k == 1) continue;
                    if(i == 0 && j == 1 && k == 2) continue;
                    if(i == 0 && j == 2 && k == 1) continue;
                    result += ans[i][j][k];
                    result %= mod;
                }
            }
        }

        return result;
    };
};


acgt three(){
    acgt tmp = acgt();
    loop(i,4){
        loop(j,4){
            loop(k,4){
                if(i == 2 && j == 0 && k == 1) continue;
                if(i == 0 && j == 1 && k == 2) continue;
                if(i == 0 && j == 2 && k == 1) continue;
                tmp.ans[i][j][k] = 1;
            }
        }
    }

    return tmp;
}

acgt dp(acgt prev){
    acgt newAcgt = acgt();
    loop(i,4){
        loop(j,4){
            loop(k,4){
                loop(l,4){
                    if(j == 2 && k == 0 && l == 1) continue;
                    if(j == 0 && k == 1 && l == 2) continue;
                    if(j == 0 && k == 2 && l == 1) continue;
                    if(i == 0 && j == 2 && l == 1) continue;
                    if(i == 0 && k == 2 && l == 1) continue;
                    newAcgt.ans[j][k][l] += prev.ans[i][j][k];
                    newAcgt.ans[j][k][l] %= mod;
                }
            }
        }
    }
    return newAcgt;
}

int main(){
    int n;
    cin >> n;

    acgt tmp = three();
    if(n == 3){
        cout << tmp.sum() << endl;
        return 0;
    }

    for(int i = 4; i <= n; i++){
        tmp = dp(tmp);
    }

    cout << tmp.sum() << endl;
    return 0;

}