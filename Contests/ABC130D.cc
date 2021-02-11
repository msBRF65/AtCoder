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
    ll n,k;
    cin >>n >>k;
    vector<int> a(n);

    loop(i,n){
        cin >> a[i];
    }

    int start, end = 0;

    ll tmpValue = a[0], result = 0;

    for(start = 0; start < n; start++){
        while(1){
            if(tmpValue >= k){
                result += n - end;
                break;
            }
            if(end == n-1) break;
            end++;
            tmpValue += a[end];
        }
        tmpValue -= a[start];
    }

    cout << result << endl;
}