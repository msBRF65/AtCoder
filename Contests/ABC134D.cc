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
    int N;
    cin >> N;
    vector<int> a(N),b(N,0);
    loop(i,N){
        cin >> a[i];
    }

    for(int i = N ; i >= 1; i--){
        int sum = 0;
        for(int j = i; j <= N; j += i){
            sum ^= b[j-1];
        }
        b[i-1] = sum^a[i-1];
    }

    vector<int> result;
    loop(i,N){
        if(b[i] == 1)result.push_back(i+1);
    }
    cout << result.size() << endl;
    loop(i,result.size()){
        cout << result[i] << " " << endl;
    }

}