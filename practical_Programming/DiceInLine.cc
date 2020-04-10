#include<iostream>
#include<algorithm>

#define loop(n) for(int ii = 0; ii<n; ii++)

using namespace std;

long long expect[200010];
long long sum[200010];

int main(){
    int k,n,p[200010];

    cin >> n >> k;
    loop(n){
        cin >> p[ii];
    }

    sum[0] = 0;
    loop(n){
        sum[ii + 1] = sum[ii] + p[ii];
    }

    loop(n-k+1){
        expect[ii] = sum[ii+k] - sum[ii];
    }
    

    sort(expect,expect+n-k+1);
    reverse(expect,expect+n-k+1);

    double ans = (expect[0] + k)/2.;
    printf("%10f",ans);

}