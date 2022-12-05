#include<iostream>
#define ll long long
#define MOD 998244353
using namespace std;
int main(){
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a %= MOD; b %= MOD; c %= MOD; d %= MOD; e %= MOD; f %= MOD;
    ll l, r;
    l = (a*b)%MOD; l = (l*c)%MOD;
    r = (d*e)%MOD; r = (r*f)%MOD;
    cout << (l-r+MOD)%MOD << endl;
    return 0; 
}