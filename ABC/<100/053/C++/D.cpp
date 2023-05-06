#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  set<int> S;
  rep(i, 0, N){
    int A; cin >> A;
    S.insert(A);
  }

  cout << (S.size() & 1 ? S.size() : S.size() - 1) << endl;
  return 0;
}