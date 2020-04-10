#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<stdio.h>

using namespace std;

int main(){
    long int N,ans1,ans2,ans3;
    cin >> N;
    vector<long int> a(N);
    for(int i = 0;i<N;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ans1 = a[0];
    ans2 = a[N-1];
    ans3 = accumulate(a.begin(),a.end(),0);
    printf("%d %d %d\n",ans1,ans2,ans3);
}