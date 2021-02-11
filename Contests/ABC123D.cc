#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
#include<map>
#include<queue>

typedef long long ll;

#define debug(x) cout << #x << '=' << x << endl;
#define debug_arr(a, n) for(ll i = 0; i < n; i++)cout << a[i] << ' '
#define inf 100000000000
#define loop(i,n) for(ll i = 0; i < n; i++)
#define graph vector<vector<ll>>
#define P pair<ll,ll>

using namespace std;

struct cakes{
    ll i;
    ll j;
    ll k;
    ll sum;

    cakes(ll i, ll j, ll k, ll sum): i(i),j(j),k(k),sum(sum){}
};

bool isChecked[1000][1000][1000] = {false};

int main(){
    ll x,y,z;
    cin >> x >> y >> z;

    ll k;
    cin >> k;

    auto compare = [](const cakes& a, const cakes& b){
        return a.sum < b.sum;
    };

    auto sortCompare = [](const ll& l, const ll& r){
        return l > r;
    };

    priority_queue<cakes, vector<cakes>, decltype(compare)> q{compare};

    vector<ll> a(x),b(y),c(z);

    loop(i,x) cin >> a[i];
    loop(i,y) cin >> b[i];
    loop(i,z) cin >> c[i];

    sort(a.begin(), a.end(), sortCompare);
    sort(b.begin(), b.end(), sortCompare);
    sort(c.begin(), c.end(), sortCompare);

    ll count = 0;
    cakes initCakes = cakes(0,0,0,a[0]+b[0]+c[0]);

    isChecked[0][0][0] = true;
    q.push(initCakes);

    while(1){
        cakes tmp = q.top();
        q.pop();
        // cout << tmp.i << tmp.j << tmp.k << endl;
        cout << tmp.sum << endl;

        if(isChecked[tmp.i + 1][tmp.j][tmp.k] == false && tmp.i + 1 < x){
            q.push(cakes(tmp.i+1,tmp.j,tmp.k,a[tmp.i+1]+b[tmp.j]+c[tmp.k]));
            isChecked[tmp.i + 1][tmp.j][tmp.k] = true;
        }
        if(isChecked[tmp.i][tmp.j+1][tmp.k] == false && tmp.j + 1 < y){
            q.push(cakes(tmp.i,tmp.j+1,tmp.k,a[tmp.i]+b[tmp.j+1]+c[tmp.k]));
            isChecked[tmp.i][tmp.j + 1][tmp.k] = true;
        }
        if(isChecked[tmp.i][tmp.j][tmp.k+1] == false && tmp.k + 1 < z){
            q.push(cakes(tmp.i,tmp.j,tmp.k+1,a[tmp.i]+b[tmp.j]+c[tmp.k+1]));
            isChecked[tmp.i][tmp.j][tmp.k+1] = true;
        }

        count ++;
        if(count == k)break;
    }

    return 0;
}