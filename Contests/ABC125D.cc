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
    int n;
    cin >> n;

    vector<int> a(n);
    loop(i,n) cin >> a[i];

    sort(a.begin(),a.end(),[](const int& l, const int& r){
        return abs(l) > abs(r);
    });

    int revN = 0;
    ll result = 0;
    loop(i,n-1){
        if(a[i] < 0){
            result -= a[i];
            revN++;
        }else{
            result += a[i];
        }
    }
    if(revN%2 == 1){
        result += a[n-1] * -1;
    }else{
        result += a[n-1];
    }

    cout << result << endl;
}