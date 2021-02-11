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
    int N, diff;
    cin >> N;
    vector<ll> A(N+1),M(N+1);
    loop(i,N){
        cin >> A[i+1];
    }
    A[0] = A[N];
    M[1] = 0;
    for(int i = 2;i <= N;i++){
        M[i] = A[i-1] * 2 - M[i-1];
    }

    diff = (A[N]*2 - (M[N] + M[1]))/2;
    
    loop(i,N-1){
        cout << M[i+1] + diff << " ";
        diff *= -1;
    }
    cout << M[N] + diff << endl;
}