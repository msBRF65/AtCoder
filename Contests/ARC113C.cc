#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>
#include<set>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    string s;
    cin >> s;

    map<char, ll> ctol;

    ll ans = 0;
    ctol[s[s.size() - 1]] = 1;
    for(int i = s.size() - 2; i >= 0; i--){
        if(s[i] == s[i+1]){
            ans += s.size() - (i + 1) - ctol[s[i]];

            map<char, ll> new_ctol;
            new_ctol[s[i]] = s.size() - (i + 1) + 1;
            ctol = new_ctol;
        } else {
            if(ctol.count(s[i]) == 0) ctol[s[i]] = 1;
            else ctol[s[i]] ++;
        }
    }

    cout << ans << endl;
}