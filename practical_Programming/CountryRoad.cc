#include<iostream>
#include<algorithm>

using namespace std;
// カントリーロード（https://onlinejudge.u-aizu.ac.jp/problems/2104）
// ポインタの範囲だけでsortをすると勘違いをしていたためsort(y,y+n-2)で実行していたので問題が解けなかった。
void CountryRoad(){
    int n,k,result;
    int x[100000],y[100000];
    cin >>n >>k;
    for(int i = 0; i<n; i++){
        cin >> x[i];
    }
    if(n <= k){
        cout << 0 << endl;
        return;
    }
    result = x[n-1]-x[0];
    if(k == 0){
        cout << result << endl;
        return;
    }
    for(int i = 0;i<n-1;i++){
        y[i] = x[i+1] - x[i];
    }
    sort(y,y+n-1);
    reverse(y,y+n-1);
    for(int i = 0; i<k-1; i++){
        result-=y[i];
    }
    cout << result << endl;
    return;
}

int main(){
    int loop;
    cin >> loop;
    while(loop != 0){
        CountryRoad();
        loop -= 1;
    }
}