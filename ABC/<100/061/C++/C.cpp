#include<iostream>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, K; cin >> N >> K;
  
  map<int, int> m;
  rep(i, 0, N){
    int a, b; cin >> a >> b;
    m[a] += b;
  }

  int k = 0;
  for(auto p : m){
    if(k + p.second >= K){
      cout << p.first << endl;
      return 0;
    }
    k += p.second;
  }
}