#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int H,W,a[2000][2000],max=0,score;
    cin >>H >>W;
    string S[2000];
    for(int i = 0;i<H;i++){
        cin >> S[i];
        for(int k =0;k<W;k++){
            if(S[i][k] == '.'){
                a[i][k] = 1;
            }
            else{
                a[i][k] = 0;
            }
        }
    }
    for(int i = 0;i<H;i++){
        for(int k=0;k<W;k++){
            score = 0;
            if(a[i][k] == 0)continue;
            for(int migi = 1;migi < W-k;migi++){
                if(a[i][k+migi] == 0)break;
                score++ ;
            }
            for(int hidari = 1;hidari <= k;hidari++){
                if(a[i][k-hidari] == 0)break;
                score++ ;
            }
            for(int ue = 1;ue <= i;ue++){
                if(a[i-ue][k] == 0)break;
                score++ ;
            }
            for(int shita = 1;shita < H-i;shita++){
                if(a[i+shita][k] == 0)break;
                score++ ;
            }
            if(score>max)max=score;
        }
    }
    cout << max << endl; 
}