#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int inf = 1000000000;
int main(){
    int a,b,ans;
    cin >>a >>b;
    if(b == 1){
        cout << 0 << endl;
        return 0;
    }
    ans = (b-1)/(a-1);
    if((b-1)%(a-1) != 0)ans++;
    cout << ans << endl;
}