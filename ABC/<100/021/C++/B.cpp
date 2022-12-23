#include<iostream>
#include<map>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  int a, b; cin >> a >> b;
  int K; cin >> K;
  map<int, int> m;
  rep(i,0,K){
    int P; cin >> P;
    m[P] += 1;
  } 
  bool flag = true;
  if(m.count(a)==1 || m.count(b)==1) flag = false;
  for(auto iter=m.begin(); iter!=m.end(); ++iter){
    if(iter->second>1){
      flag = false;
      break;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}