#include<iostream>
#include<stdio.h>

using namespace std;

int a,b;

int main(){
    cin >> a >> b;
    printf("%d %d %.8f",a/b,a%b,(double)a/(double)b);
}