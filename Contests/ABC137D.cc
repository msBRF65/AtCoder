#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void show(vector<vector <int>> v,int N){
    for(int i=0;i<N;i++){
        cout << v[i][0] << " " << v[i][1] << endl;
    }
}

int main(){
    int N,M,last_num = 0,ans=0;
    cin >>N >>M;
    vector<int> a(2);
    vector< vector<int>> jobs(N,a);
    priority_queue<int> q;

    //日数、報酬
    for(int i=0; i<N; i++){
        cin >>jobs[i][0] >>jobs[i][1];
    }
    sort(jobs.begin(),jobs.end());
    //show(jobs,N);
    for(int i=1;i<=M;i++){
        while(last_num != N){
            if(jobs[last_num][0] <= i){
                q.push(jobs[last_num][1]);
                last_num++;
            }
            else break;
        }
        if(q.empty())continue;
        else{
            ans += q.top();
            //cout << ans << endl;
            q.pop();
        }
    }
    cout << ans << endl;
}