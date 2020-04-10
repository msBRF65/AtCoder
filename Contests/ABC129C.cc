#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int N,M,a[100000],way[100001],a_num;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> a[i];
    }
    way[0] = 1;
    way[1] = 1;
    a_num = 0;
    if(a[0] == 1){
        a_num = 1;
        way[1] = 0;
    }
    for(int i=2;i<=N;i++){
        if(a[a_num] == i){
            way[i] = 0;
            a_num ++;
        }
        else{
            way[i] = way[i-1] + way[i-2];
            way[i] %= 1000000007;
        }
    }
    cout << way[N] << endl;
}