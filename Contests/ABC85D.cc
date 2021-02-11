#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
#include<deque>
#include<map>
#include<queue>
#include<cmath>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct attack {
    int damage;
    bool is_throw;
};

int main(){
    ll n,h;
    cin >> n >> h;

    ll array_size = n * 2;
    vector<attack> attack_array(array_size);

    loop(i, n){
        int a,b;
        cin >> a >> b;

        attack_array[i * 2].damage = a;
        attack_array[i * 2].is_throw = false;

        attack_array[i * 2 + 1].damage = b;
        attack_array[i * 2 + 1].is_throw = true;
    }

    sort(attack_array.begin(), attack_array.end(), [](attack l, attack r){
        return l.damage > r.damage;
    });

    ll dmg_sum = 0;
    ll attack_num = 0;

    loop(i, n * 2){   
        attack tmp_attack = attack_array[i];
        if(tmp_attack.is_throw){
            dmg_sum += tmp_attack.damage;
            attack_num ++;

            if(dmg_sum >= h){
                cout << attack_num << endl;
                break;
            }
        }else{
            attack_num += (h - dmg_sum) / tmp_attack.damage;
            if((h - dmg_sum) % tmp_attack.damage != 0) attack_num ++;

            cout << attack_num << endl;
            break;
        }
    }

    return 0;
}