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

int main(){
    int a,b,q;
    cin >> a >> b >> q;
    
    vector<ll> s(a),t(b),x(q);
    loop(i,a) cin >> s[i];
    loop(i,b) cin >> t[i];
    loop(i,q) cin >> x[i];

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    loop(i,q){
        ll tmpx = x[i];
        int startS = -1;
        int endS = a;
        while(startS + 1 < endS){
            int tmp = (startS + endS) / 2;
            if(s[tmp] < tmpx){
                startS = tmp;
            }else{
                endS = tmp;
            }
        }
        int startT = -1;
        int endT = b;
        while(startT + 1 < endT){
            int tmp = (startT + endT) / 2;
            if(t[tmp] < tmpx){
                startT = tmp;
            }else{
                endT = tmp;
            }
        }

        ll ans1,ans2,ans3;
        if(startS == -1 || startT == -1) ans1 = inf;
        else ans1 = tmpx - min(s[startS],t[startT]);

        if(endS == a || endT == b) ans2 = inf;
        else ans2 = max(s[endS],t[endT]) - tmpx;
        
        ll minS, minT;
        if(startS == -1)minS = s[endS] - tmpx;
        else if(endS == a) minS = tmpx - s[startS];
        else minS = min(tmpx - s[startS], s[endS] - tmpx);

        if(startT == -1)minT = t[endT] - tmpx;
        else if(endT == b) minT = tmpx - t[startT];
        else minT = min(tmpx - t[startT], t[endT] - tmpx);

        ans3 = minS + minT + min(minS,minT);

        cout << min(ans1,min(ans2,ans3)) << endl;
    }

    return 0;
}