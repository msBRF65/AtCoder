#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)

using namespace std;

pair<int,int> getPair(ll n){
    int last = n % 10;
    int top = 0;
    while(n){
        top = n;
        n /= 10;
    }

    pair<int,int> result = make_pair(top, last);

    return result;
}

int main(){
    ll n;
    vector<ll> a(100);
    map<pair<int,int>,int> freq;
    cin >>n;

    loop(i,n){
        ll ii = n-i;
        pair<int,int> a = getPair(ii);
        freq[a]++;
    }

    ll ans = 0;

    loop(i,n){
        ll ii = n-i;
        pair<int,int> a = getPair(ii);
        pair<int,int> b(a.second,a.first);

        ans += freq[b];
    }

    cout << ans << endl;

    return 0;
}