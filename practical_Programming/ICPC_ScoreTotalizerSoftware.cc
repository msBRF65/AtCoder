#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,score[101],sum;
    while(cin >>n && n>0){
        for(int i=0; i<n; i++){
            cin >>score[i];
        }
        sort(score,score+n);
        sum = 0;
        for(int i=1; i<n-1; i++){
            sum += score[i];
        }
        cout << sum/(n-2) << endl;
    }
    return 0;
}