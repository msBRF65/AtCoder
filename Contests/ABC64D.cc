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
    cin >> n;

    string s;
    cin >> s;

    ll l = 0, r = 0;

    loop(i, n){
        if(s[n - 1 - i] == ')') l++;
        else if(l > 0) l--;

        if(s[i] == '(') r++;
        else if(r > 0) r--; 
    }

    loop(i, l) cout << '(';
    cout << s;
    loop(i, r) cout << ')';
}