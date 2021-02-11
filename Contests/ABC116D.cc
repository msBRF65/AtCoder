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
    int n,k;
    cin >> n >> k;

    vector<vector<int>> sushi(n);

    loop(i,n){
        int t,d;
        cin >> t >> d;
        sushi[t-1].push_back(d);
    }

    loop(i,n){
        if(sushi[i].size() == 0)continue;
        sort(sushi[i].begin(),sushi[i].end(),[](const auto& l,const auto& r){
            return l > r;
        });
    }
    sort(sushi.begin(),sushi.end(),[](const auto& l, const auto& r){
        if(l.size() == 0) return false;
        if(r.size() == 0) return true;
        return l[0] > r[0];
    });

    ll result = 0;
    int sushiNum = 0;
    for(int i = 0; i < min(n,k); i++){
        sushiNum += sushi[i].size();
        if(sushiNum < k)continue;
        ll oishisa = 0;
        priority_queue<int> q;

        if(sushi[i].size() == 0)break;
        loop(j,i+1){
            oishisa += sushi[j][0];
            for(int m = 1; m < sushi[j].size(); m++){
                q.push(sushi[j][m]);
            }
        }

        for(int j = i + 1; j < k; j++){
            oishisa += q.top();
            q.pop();
        }
        result = max(oishisa + (i+1)*(i+1), result);
    }

    cout << result << endl;
}