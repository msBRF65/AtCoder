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
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct Score {
    ll x;
    ll y;
    ll z;

    Score(ll xx, ll yy, ll zz){
        this -> x = xx;
        this -> y = yy;
        this -> z = zz;
    }

    ll total_score(ll a, ll b, ll c){
        return (a * 2 - 1) * x + (b * 2 - 1) * y + (c * 2 - 1) * z;
    }
};

int main(){
    ll n,m;
    cin >> n >> m;

    ll ans = -inf;
    vector<Score> cakes;

    loop(i,n){
        ll x, y, z;
        cin >> x >> y >> z;
        cakes.emplace_back(x, y, z);
    }

    loop(i,8){
        ll a, b, c;
        a = i % 2;
        b = (i >> 1) % 2;
        c = (i >> 2) % 2;

        vector<ll> scores;
        loop(j,n){
            scores.push_back(cakes[j].total_score(a,b,c));
        }

        sort(scores.begin(), scores.end());
        reverse(scores.begin(), scores.end());

        ll sum_score = 0;
        loop(j,m){
            sum_score += scores[j];
        }

        ans = max(ans, sum_score);
    }

    cout << ans << endl;
}