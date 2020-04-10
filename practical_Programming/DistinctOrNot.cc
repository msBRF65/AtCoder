#include<iostream>
#include<algorithm>

using namespace std;

#define loop(n) for(int ii = 0; ii<n; ii++)

int main(){
    int n;
    long long int a[300000];
    
    cin >> n;
    loop(n){
        cin >> a[ii];
    }
    
    sort(a,a+n);

    loop(n-1){
        if(a[ii] == a[ii+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}