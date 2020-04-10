#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,w[100],ws[100],sum = 0;
    cin >> n;
    for (int i =0;i<n;i++){
        cin >> w[i];
        sum += w[i];
    }
    ws[0] = w[0];
    for (int i = 1;i<n;i++){
        ws[i] = ws[i-1] + w[i];
    }
    for (int i = 0;i<n;i++){
        if(sum > 2*ws[i]){
            ws[i] = sum - 2*ws[i];
        }
        else{
            ws[i] = 2*ws[i] -sum;
        }
    }
    sort(ws,ws+n-1);
    cout << ws[0] <<endl;
}