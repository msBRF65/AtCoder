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

double e[100][100][100];

double get_e(ll a, ll b, ll c){
    ll x, y, z;
    vector<ll> v = {a,b,c};
    reverse(v.begin(), v.end());

    x = v[0], y = v[1], z = v[2];

    if(x == 100 || y == 100 || z == 100) return 0;
    if(e[x][y][z] != 0) return e[x][y][z];

    else {
        double new_e;
        if(y == 0 && z == 0) new_e = get_e(x + 1, y , z) + 1;
        else if(z == 0) new_e = ((get_e(x + 1, y , z) + 1) * x + (get_e(x, y + 1, z) + 1) * y) / (x + y);
        else new_e = ((get_e(x + 1, y, z) + 1) * x + (get_e(x, y + 1, z) + 1) * y + (get_e(x, y, z + 1) + 1) * z) / (x + y + z);

        e[x][y][z] = new_e;
        e[y][x][z] = new_e;
        e[z][x][y] = new_e;
        e[x][z][y] = new_e;
        e[z][y][x] = new_e;
        e[y][z][x] = new_e;

        return e[x][y][z];
    }
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;

    loop(i, 100){
        loop(j, 100){
            loop(k, 100) e[i][j][k] = 0;
        }
    }

    printf("%.6lf", get_e(a,b,c));

    return 0;
}