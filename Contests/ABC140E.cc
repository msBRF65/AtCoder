#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
long long int pattern(int a,int b,int n){
    int temp;
    if(a<b){
        temp = b;
        b = a;
        a = temp;
    }
    //a>b
    //cout << "aa" << endl;
    return (n-a+1)*b;
}
 
bool cmp(vector<int> &a ,vector<int> &b){
    return a[0] > b[0];
}

int main(){
    int n,big,bigg,temp;
    long long int ans=0;
    cin >> n;
    vector<int> a(2,0);
    vector<vector<int> > p;
    //数字、順番
    for(int i=0;i<n;i++){
        cin >> a[0];
        a[1] = i+1;
        p.push_back(a);
    }
    //cout << p[1][0] << " " << p[1][1] << endl;
    sort(p.begin(),p.end(),cmp);
    cout << p[0][0] << " " << p[0][1] << endl;
    //cout << p[1][0] << " " << p[1][1] << endl;
    for(int i=0;i<n-1;i--){
        big = p[i][1];
        bigg = p[i+1][1];
        //cout << big << " " << bigg << endl;
        temp = pattern(big,bigg,n);
        //cout << "a" << endl;
        ans += temp;
    }
    cout << ans << endl;
}