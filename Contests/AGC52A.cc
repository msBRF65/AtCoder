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

string solve(){
    ll n;
    string s1, s2, s3;
    cin >> n >> s1 >> s2 >> s3;

    s1 += s1;
    s2 += s2;
    s3 += s3;

    ll tmp1 = -1, tmp2 = -1, tmp3 = -1;
    ll next01, next02, next03, next11, next12, next13;

    
}

int main(){
    ll t;
    cin >> t;

    vector<string> ans;

    loop(i, t) ans.push_back(solve());

    loop(i,t) cout << ans[i] << endl;
}