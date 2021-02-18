#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>
#include<set>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

int main(){
    string s;
    ll x, y;
    cin >> s;
    cin >> x >> y;

    vector<ll> x_block;
    vector<ll> y_block;

    ll tmp = 0;
    bool is_x = true;
    loop(i, s.size()){
        if(s[i] == 'F') tmp++;
        else {
            if(is_x) x_block.push_back(tmp);
            else y_block.push_back(tmp);

            tmp = 0;
            is_x = (1 - is_x);
        }
        if(i == s.size() - 1 && tmp > 0){
            if(is_x) x_block.push_back(tmp);
            else y_block.push_back(tmp);
        }
    }

    vector<ll> x_sum, y_sum;
    
    set<ll> x_available;
    x_available.insert(x_block[0]);

    x_block[0] = 0;
    for(ll v: x_block){
        set<ll> tmp;
        for(ll xx: x_available){
            tmp.insert(xx + v);
            tmp.insert(xx - v);
        }
        x_available = tmp;
    }

    set<ll> y_available;
    y_available.insert(0);

    for(ll v: y_block){
        set<ll> tmp;
        for(ll yy: y_available){
            tmp.insert(yy + v);
            tmp.insert(yy - v);
        }
        y_available = tmp;
    }

    if(x_available.count(x) && y_available.count(y)) cout << "Yes" << endl;
    else cout << "No" << endl;
}