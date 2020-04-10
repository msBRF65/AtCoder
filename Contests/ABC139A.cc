#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int inf = 1000000000;
int main(){
    int ans = 0;
    string a,b;
    cin >>a >>b;
    for(int i=0;i<3;i++){
        if(a[i] == b[i])ans++;
    }
    cout << ans << endl;
}