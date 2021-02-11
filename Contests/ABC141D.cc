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
    ll n,m,result = 0;
    cin >>n >>m;

    vector<ll> a(n);
    priority_queue<ll> q;
    
    loop(i,n) {
        cin >>a[i];
        q.push(a[i]);
    }

    loop(i,m){
        ll tmp = q.top();
        q.pop();
        tmp /= 2;
        q.push(tmp);
    }

    loop(i,n){
        result += q.top();
        q.pop();
    }

    cout << result << endl;
}