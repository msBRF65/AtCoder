#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> ans(n+1);

    for(int i=1;i<n;i++){
        for(int k=i+1;k<=n;k++){
           int _min = min(abs(k-i),abs(x-i)+abs(y-k)+1);
           ans[_min]++;
        }
    }

    for(int i=1;i<n;i++){
        cout << ans[i] << endl;
    }

    return 0;
}