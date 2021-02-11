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
    ll n,min,max,minIndex,maxIndex,a,b,result = 0;
    cin >>n;

    vector<ll> l(n);
    loop(i,n) cin >>l[i];

    sort(l.begin(),l.end());

    loop(i,n-1){
        for(ll j = i+1; j<=n-1; j++){
            a = l[i];
            b = l[j];

            min = b - a + 1;
            max = a + b - 1;
            if(min > max)continue;
            if(min > l[n-1] || max < l[0])continue;

            ll noIndex,okIndex,mid;

            noIndex = -1;okIndex = n;
            while(noIndex + 1 < okIndex){
                mid = (noIndex + okIndex) / 2;
                if(min <= l[mid]){
                    okIndex = mid;
                }else{
                    noIndex = mid;
                }
            }
            minIndex = noIndex;

            noIndex = n;okIndex = -1;
            while(okIndex + 1 < noIndex){
                mid = (noIndex + okIndex) /2;
                if(l[mid] <= max){
                    okIndex = mid;
                }else{
                    noIndex = mid;
                }
            }
            maxIndex = noIndex;

            // debug(max);
            // debug(min);
            // debug(maxIndex);
            // debug(minIndex);

            if(maxIndex < minIndex) continue;

            result += maxIndex - minIndex - 1;
            if(minIndex < i && i < maxIndex) result--;
            if(minIndex < j && j < maxIndex) result--;
        }
    }
    cout << result / 3 << endl;
}