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

struct job {
    int time;
    int deadline;
};

bool compare(const job& l, const job& h){
    return l.deadline < h.deadline;
}

int main(){
    int n;
    cin >> n;
    vector<job> todo(n);
    loop(i,n){
        cin >> todo[i].time >> todo[i].deadline;
    }

    sort(todo.begin(), todo.end(), compare);

    long long time = 0;
    loop(i,n){
        // cout << todo[i].time << todo[i].deadline << endl;
        time += todo[i].time;
        if(time > todo[i].deadline){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;

}