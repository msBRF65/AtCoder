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
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    ll n,k,r,s,p;
    cin >>n >>k;
    cin >>r >>s >>p;
    vector<ll> score(n);

    string t;
    cin >>t;

    loop(i,n){
        char hand = t[i];
        if(i-k >= 0){
            if(t[i] == t[i-k]){
                if(score[i-k] != 0) {
                    score[i] = 0;
                    continue;
                }
            }
        }
        if(hand == 'r'){
            score[i] = p;
        }else if (hand == 's')
        {
            score[i] = r;
        }else if (hand == 'p')
        {
            score[i] = s;
        }
    }
    ll result = 0;
    loop(i,n){
        result += score[i];
    }

    cout << result << endl;
}