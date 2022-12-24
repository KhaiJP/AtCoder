#include<iostream>
#include<atcoder/dsu>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;
using namespace atcoder;
int main(){
  int N, M; cin >> N >> M;
  dsu uf(N);
  rep(i,0,M){
    int A, B; cin >> A >> B;
    uf.merge(A-1, B-1);
  }
  int answer = 0;
  rep(u,0,N) answer = max(answer, uf.size(u));
  cout << answer << endl;
  return 0;
}