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
#define inf 1000000000000000000
#define loop(i,n) for(ll i = 0; i < n; i++)

using namespace std;

int main(){
    ll n,k;
    cin >>n >>k;
    vector<ll> a(n);
    loop(i,n) cin >> a[i];
    sort(a.begin(),a.end());

    ll l = -inf, r = inf;
    
    // ある数x未満の積の数がk-1になるような最小のxを求める
    while(l+1 < r){
        ll mid = (r + l)/2;
        bool ok = [&]{
            ll total = 0;
            loop(i,n){
                ll l = -1,r = n;
                if(a[i] < 0){
                    while(l+1 < r){
                        ll aNum = (r+l)/2;
                        if(a[i] * a[aNum] < mid) r = aNum;
                        else l = aNum;
                    }
                    total += (n-r);
                }else{
                    while(l+1 < r){
                        ll aNum = (r+l)/2;
                        if(a[i] * a[aNum] < mid) l = aNum;
                        else r = aNum;
                    }
                    total += r;
                }
                if(a[i]* a[i] < mid) total --;
            }
            total /= 2;
            return total < k;
        }();

        if(ok) l = mid;
        else r = mid;
    }

    cout << l << endl;
    return 0;
}


