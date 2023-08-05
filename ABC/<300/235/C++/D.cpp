#include<iostream>
#include<string>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll a, N;
int dist[10000010];


ll rotate(ll x){
  string xs = to_string(x);
  string s = xs.back() + xs; s.erase(s.size()-1);
  return stoi(s);
}

int main(){
  cin >> a >> N;
  ll M = 1;
  while (M <= N) M *= 10;
  
  queue<ll> q; q.push(1);
  while(q.size()){
    ll n = q.front(); q.pop();
    ll d = dist[n];

    ll an = a * n;
    if(an < M && dist[an] == 0 ){
      dist[an] = d + 1;
      q.push(an);
    }

    ll rn = -1;
    if(n > 10 && n % 10 != 0){
      rn = rotate(n);
      if(rn < M && dist[rn] == 0){
        dist[rn] = d + 1;
        q.push(rn);
      }
    }

    if(an == N || rn == N){
      cout << d + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}