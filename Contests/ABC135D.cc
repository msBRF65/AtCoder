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

int charToInt(char a){
    return a - '0';
}

void updateModArray(int *a){
    loop(i,10){
        a[i] = (a[i] * 10) % 13;
    }
}

int main(){
    string s;
    ll MOD = 1000000007;
    int mod[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<ll> ans(13,0);
    cin >> s;

    ans[0] = 1;
    for(int i = s.size()-1;i >= 0; i--){
        
        vector<ll> updatedAns(13,0);
        if(s[i] == '?'){
            loop(i,10){
                loop(j,13){
                    updatedAns[(j+mod[i]) % 13] += ans[j];
                }
            }
        }else{
            int num = charToInt(s[i]);
            loop(j,13){
                updatedAns[(j + mod[num]) % 13] += ans[j];
            }
        }

        loop(i,13){
            updatedAns[i] %= MOD;
        }

        ans = updatedAns;
        updateModArray(mod);

    }


    cout << ans[5] << endl;
}