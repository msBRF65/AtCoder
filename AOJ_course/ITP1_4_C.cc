#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){
    int a,b;
    string shiki;
    queue<int> q;
    while(1){
        cin >>a >>shiki >>b;
        if(shiki == "+")q.push(a+b);
        else if(shiki == "-")q.push(a-b);
        else if(shiki == "/")q.push(a/b);
        else if(shiki == "*")q.push(a*b);
        else if(shiki == "?")break;
    }
    while(1){
        cout << q.front() << endl;
        q.pop();
        if(q.empty())break;
    }
}