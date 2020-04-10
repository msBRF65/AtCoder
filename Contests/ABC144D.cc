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
    ll a,b,x;
    cin >>a >>b >>x;

    double d = double(x) / a, result;

    if(d * 2 > a * b){
        double c = d * 2.0 / b;
        debug(c);
        result = atan2(b , c);
    }else{
        d = (a * b) - d;
        double c = d * 2.0 / a;
        result = atan2(c , a);
    }

    double pi = acos(-1);
    result = result / (2.0 * pi) * 360;

    printf("%.10f",result);

    return 0;
}