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

int pow_10_mod_2019(int n){
    if(n == 0) return 1;
    else if(n == 1) return 10;
    else if(n % 2 == 1){
        int tmp = pow_10_mod_2019(n / 2);
        return tmp * tmp * 10 % 2019;
    }else{
        int tmp = pow_10_mod_2019(n / 2);
        return tmp * tmp % 2019;
    }
}

int main(){
    string s;
    cin >> s;

    int count[2019] = {0};
    count[0] = 1;

    int before = 0;
    for(int i = 1; i <= s.size(); i++){
        int tmp_num = (int)s[s.size() - i] - '0';
        int tmp_digit_mod = pow_10_mod_2019(i - 1);
        int tmp_mod = (tmp_num * tmp_digit_mod + before) % 2019;

        count[tmp_mod] += 1;
        before = tmp_mod;
    }

    int result = 0;
    loop(i, 2019){
        result += count[i] * (count[i] - 1) / 2;
    }

    cout << result << endl;
}