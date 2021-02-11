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

int main(){
    string s;
    cin >> s;
    vector<ll> ans(s.size(),1);

    loop(i, s.size()){
        if(s[i] == 'R'){
            if(s[i+1] == 'R'){
                ans[i+2] += ans[i];
                ans[i] = 0;
            }
        }
    }
    for(ll i = s.size()-1;i >= 0;i--){
        if(s[i] == 'L'){
            if(s[i-1] == 'L'){
                ans[i-2] += ans[i];
                ans[i] = 0;
            }
        }
    }
    loop(i, s.size()){
        cout << ans[i] << endl;
    }
}