#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int p,q,r,sum = 0,max;
    cin >> p;
    sum += p;
    max = p;
    cin >> q;
    sum += q;
    if(q > max)max = q;
    cin >> r;
    sum += r;
    if(r > max)max = r;
    cout << sum - max << endl;

}