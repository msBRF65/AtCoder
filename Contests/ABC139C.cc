#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int inf = 1000000000;
int main(){
    int N;
    cin >> N;
    vector<int> H(N),ans(N);
    for(int i=0;i<N;i++){
        cin >>H[i];
    }
    ans[N-1]=0;
    for(int i=N-2;i>=0;i--){
        if(H[i]>=H[i+1])ans[i]=ans[i+1]+1;
        else ans[i] = 0;
    }
    sort(ans.begin(),ans.end());
    cout << ans[N-1] << endl;
}