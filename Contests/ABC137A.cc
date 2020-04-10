#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a,b,tasu,hiku,kakeru,ans;
    cin >> a >> b;
    tasu = a + b;
    ans = tasu;
    hiku = a - b;
    if(hiku > ans){
        ans = hiku;
    }
    kakeru = a * b;
    if(kakeru > ans){
        ans = kakeru;
    }
    cout << ans << endl;
}