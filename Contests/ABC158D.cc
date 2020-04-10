#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>

typedef long long ll;

#define debug(x) cout << #x << "=" << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << " "
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)

using namespace std;

int main(){
    string str;
    cin >> str;
    ll queryNum;
    cin >> queryNum;

    int t,f,isReverse = -1;
    deque<char> dequeChar;
    char c; 

    for(char ch: str){
        dequeChar.push_back(ch);
    }

    loop(i,queryNum){
        cin >> t;
        if(t == 1) isReverse *= -1;
        else if(t == 2){
            cin >> f >> c;
            if(isReverse == -1){
                if(f == 1)dequeChar.push_front(c);
                if(f == 2)dequeChar.push_back(c);
            }else{
                if(f == 2)dequeChar.push_front(c);
                if(f == 1)dequeChar.push_back(c);
            }
        }
    }
    
    if(isReverse == -1){
        loop(i, dequeChar.size()){
            cout << dequeChar[i];
        }
    }else{
        for(ll i = dequeChar.size() - 1; i >= 0; i--){
            cout << dequeChar[i];
        }
    }
    cout << endl;

    return 0;
}