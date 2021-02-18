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
    ll a,b;
    cin >> a >> b;

    bool is_black[100][100];

    loop(i,100){
        loop(j,100){
            if(i < 50) is_black[i][j] = true;
            else is_black[i][j] = false;
        }
    }

    ll tmp = 0;
    loop(i,a - 1){
        is_black[tmp / 100][tmp % 100] = false;
        tmp += 2;
        if(tmp % 100 == 0)tmp += 100;
    }
    tmp = 100 * 100 - 1;
    loop(i, b - 1){
        is_black[tmp / 100][tmp % 100] = true;
        tmp -= 2;
        if(tmp % 100 == 99) tmp -= 100;
    }

    cout << 100 << " " << 100 << endl;
    loop(i,100){
        loop(j, 100){
            if(is_black[i][j]) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
}