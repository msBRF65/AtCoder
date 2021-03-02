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
    ll t;
    cin >> t;
    
    vector<string> s(t);
    loop(i,t) cin >> s[i];

    loop(i,t){
        ll a_num = 0;
        ll b_num = 0;
        ll last_b_num = 0;
        ll last_a_num = 0;
        loop(j, s[i].size()){
            if(s[i][j] == 'a') {
                a_num ++;
                last_b_num = 0;
            }
            else {
                b_num ++;
                last_b_num ++;
            }
        }

        if(b_num == 0) {
            cout << s[i] << endl;
            continue;
        }
        else {
            if(b_num - last_b_num + 2 <= last_b_num && a_num % 2 == 1) {
                last_b_num = b_num - last_b_num - 1;
                b_num = b_num - 2;
            }

            loop(j, b_num - last_b_num) cout << 'b';
            if(a_num % 2 == 1) cout << 'a';
            loop(j, last_b_num) cout << 'b';
            cout << endl;
        }
    }
}