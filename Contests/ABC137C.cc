#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

string s;
char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(){
    long int N,ans = 0;
    vector<int> al(26,0);
    bool ana;
    cin >> N;
    vector< vector<int>> snum(N,al);
    map<string,int> map;

    for(int i = 0;i < N; i++){
        cin >> s;
        sort(s.begin(),s.end());
        if(map.find(s) == map.end()){
            map[s] = 1;
        }
        else{
            ans += map[s];
            map[s]++;
        }
        /*for(int a = 0;a<26;a++){
            snum[i][a] = count(s[i].begin(),s[i].end(),alpha[a]);
        }*/
    }
    /*sort(snum.begin(),snum.end());
    for(int i = 0;i < N-1; i++){
        for(int j = i+1; j<N; j++){
            if(snum[i] == snum[j]){
                ans ++;
            }
            else break;
        }
    }*/
    cout << ans << endl;
}