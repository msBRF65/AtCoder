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

int main(){
    ll n;
    string s1, s2;

    cin >> n;
    cin >> s1;
    cin >> s2;

    vector<ll> domino;

    ll mod = 1e9 + 7;

    loop(i,n){
        if(s1[i] == s2[i]) domino.push_back(1);
        else{
            domino.push_back(2);
            i ++;
        }
    }

    ll ans;
    
    if(domino[0] == 1) ans = 3;
    else ans = 6;
    
    for(int i = 1;i < domino.size(); i++){
        if(domino[i - 1] == 1 && domino[i] == 1) ans = (ans * 2) % mod;
        else if(domino[i - 1] == 1 && domino[i] == 2) ans = (ans * 2) % mod;
        else if(domino[i - 1] == 2 && domino[i] == 1) ans *= 1;
        else if(domino[i - 1] == 2 && domino[i] == 2) ans = (ans * 3) % mod;
    }

    cout << ans << endl;
}