#include<iostream>

using namespace std;

bool check(int x,int W,int r){
    if(x-r < 0 || x+r > W){
        return false;
    }
    else return true;
}

int main(){
    int W,H,x,y,r;
    cin >>W >>H >>x >>y >>r;
    if(check(x,W,r)&&check(y,H,r))cout << "Yes" << endl;
    else cout << "No" << endl;
}