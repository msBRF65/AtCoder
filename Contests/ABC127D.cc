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
#define debug_arr(a, n) for(ll i = 0; i < n; i++){cout << a[i] << ' ';} cout << "\n" << endl;
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct step{
    int b,c;
};

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    vector<step> s(m);

    loop(i,n){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    loop(i,m){
        cin >> s[i].b >> s[i].c;
    }

    sort(s.begin(),s.end(),[](const step& l, const step& r){
        return l.c > r.c;
    });

    int cnt = 0;
    int tmpA = 0;
    int tmpS = 0;
    int tmpB = 0;

    while(1){
        if(a[tmpA] > s[tmpS].c){
            break;
        }
        a[tmpA] = s[tmpS].c;
        tmpA++;
        tmpB++;
        if(tmpB == s[tmpS].b){
            tmpB = 0;
            tmpS++;
        }
        if(tmpS == m)break;
    }

    ll result = 0;
    loop(i,n){
        // debug(a[i]);
        result += a[i];
    }

    cout << result << endl;
}