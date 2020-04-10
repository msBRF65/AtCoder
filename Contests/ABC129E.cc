#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int a[100001],sum = 0,len;
    string N;
    cin >> N;
    len = N.length();
    for(int i = 0;i < len;i++){
        a[i] = (int)N[i];
        sum += a[i];
    }

}