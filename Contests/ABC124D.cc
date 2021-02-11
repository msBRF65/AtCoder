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
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    int revN = 0;
    loop(i,n-1){
        if(s[i] != s[i+1])revN++;
    }

    vector<int> a(revN+3, 0);

    int count;
    
    if(s[0] == '1'){
        count = 0;
        a[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1])count++;
            a[count]++;
        }
    }else{
        a[0] = 0;
        a[1] = 1;
        count = 1;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1])count++;
            a[count]++;
        }
    }

    int result = 0;
    int tmpSum = 0;
    int l=0,r=2*k;
    if(r >= a.size()){
        cout << n << endl;
        return 0;
    }

    for(int i=l; i<=r; i++){
        tmpSum += a[i];
    }
    result = tmpSum;
    while(1){
        if(r+2 >= a.size())break;
        tmpSum += a[r+1] + a[r+2];
        tmpSum -= a[l] + a[l+1];
        result = max(result,tmpSum);

        l+=2;
        r+=2;
    }

    cout << result << endl;
}