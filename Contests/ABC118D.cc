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

struct match{
    int num;
    int matchNum;
};

vector<int> maxVec(vector<int> a, vector<int> b){
    if(a.size() > b.size()) return a;
    else if(a.size() < b.size()) return b;

    loop(i,a.size()){
        if(a[i] > b[i]) return a;
        else if(a[i] < b[i]) return b;
    }

    return a;
}

int main(){
    int n,m;
    cin >> n >> m;

    int matchNum[9] = {2,5,5,4,5,6,3,7,6};

    vector<match> a(m);
    loop(i,m){
        cin >> a[i].num;
        a[i].matchNum = matchNum[a[i].num - 1];
    }

    sort(a.begin(),a.end(),[](const match& l, const match& r){
        if(l.matchNum == r.matchNum){
            return l.num > r.num;
        }
        return l.matchNum < r.matchNum;
    });

    vector<match> tmp;
    tmp.push_back(a[0]);
    for(int i = 1; i < m; i++){
        if(a[i-1].matchNum == a[i].matchNum){
            continue;
        }
        tmp.push_back(a[i]);
    }
    a = tmp;

    vector<vector<int>> dp(n);

    loop(i,n){
        vector<int> result;
        loop(j,a.size()){
            vector<int> tmp;
            if(a[j].matchNum == i+1){
                tmp.push_back(a[j].num);
            }else if(a[j].matchNum > i+1){
                continue;
            }else{
                tmp = dp[i - a[j].matchNum];
                if(tmp.size() == 0)continue;
                tmp.push_back(a[j].num);
                sort(tmp.begin(),tmp.end(),[](const int& l, const int& r){
                    return l > r;
                });
            }
            result = maxVec(tmp,result);
        }
        dp[i] = result;
    }
    loop(i,dp[n-1].size()){
        cout << dp[n-1][i];
    }

    return 0;
}