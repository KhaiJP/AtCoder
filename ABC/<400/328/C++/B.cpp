#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, answer;

bool is_repdigits(int a, int b){
  set<int> s;
  while(a){
    s.insert(a%10);
    a /= 10;
  }
  while(b){
    s.insert(b%10);
    b /= 10;
  }
  return s.size() == 1;
}

int main(){
  cin >> N;
  rep(i, 1, N+1){
    int D; cin >> D;
    rep(j, 1, D+1) answer += is_repdigits(i,j);
  }

  cout << answer << endl;
  return 0;
}