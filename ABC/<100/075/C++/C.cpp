#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[55], B[55];

int main(){
  int N, M; cin >> N >> M;

  rep(i, 0, M){
    cin >> A[i] >> B[i];
    --A[i], --B[i];
  }

  int answer = 0;
  rep(i, 0, M){
    dsu uf(N);
    rep(j, 0, M)if(j != i) uf.merge(A[j], B[j]);
    
    answer += uf.groups().size() != 1;
  }

  cout << answer << endl;
  return 0;
}