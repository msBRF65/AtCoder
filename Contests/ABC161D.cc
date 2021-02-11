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

void checker(ll& k, ll& count, priority_queue<ll, vector<ll>, greater<ll>>& q, const ll& value){
    count ++;
    if(k == count){
        cout << value << endl;
    }
    q.push(value);
};

int main(){
    ll k, count = 0;
    cin >> k;


    priority_queue<ll, vector<ll>, greater<ll>> q;

    loop(i, 9){
        checker(k, count, q, i+1);
    }

    while(count < k){
        ll tmp = q.top();
        q.pop();
        ll tmp_last = tmp % 10;

        if(tmp_last == 0){
            checker(k, count, q, tmp * 10 + tmp_last);
            checker(k, count, q, tmp * 10 + 1);
        }else if(tmp_last == 9){
            checker(k, count, q, tmp * 10 + tmp_last - 1);
            checker(k, count, q, tmp * 10 + tmp_last);
        }else{
            checker(k, count, q, tmp * 10 + tmp_last - 1);
            checker(k, count, q, tmp * 10 + tmp_last);
            checker(k, count, q, tmp * 10 + tmp_last + 1);
        }
    }

    return 0;
}