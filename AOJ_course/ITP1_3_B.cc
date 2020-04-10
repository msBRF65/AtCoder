#include<iostream>
#include<queue>

using namespace std;

int main(){
    int tmp,i;
    queue<int> q;
    while(1){
        cin >>tmp;
        if(tmp == 0)break;
        q.push(tmp);
    }
    i = 1;
    while(1){
        cout << "Case " << i << ": " << q.front() <<endl;
        i++;
        q.pop();
        if(q.empty() == 1)break;  
    }
}
