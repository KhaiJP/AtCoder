#include<iostream>
#include<map>
#define ll long long
using namespace std;

map<ll, ll> m;
// memorization
ll f(ll k){
    if(m.count(k)==1) return m[k];
    else return m[k] = f(k/2) + f(k/3);
}

int main(){
    ll N; cin >> N;
    m[0] = 1;
    cout << f(N) << endl;
    return 0;
}