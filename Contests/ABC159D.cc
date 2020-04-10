#include<iostream>
#include<algorithm>
#include<vector>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)

using namespace std;

ll conbination(ll n){
    return n * (n-1) / 2;
}

int main(){
    ll n;
    ll totalNum = 0;
    cin >> n;
    vector<ll> a(n), num(n+1, 0) ;
    loop(i,n){
        cin >> a[i];
        num[a[i]]++;
    }

    loop(i,n+1){
        totalNum += conbination(num[i]);
    }

    loop(i,n){
        if(num[a[i]] == 0 || num[a[i]] == 1)cout << totalNum << endl;
        else cout << totalNum - num[a[i]] + 1 << endl;
    }

    return 0;
}