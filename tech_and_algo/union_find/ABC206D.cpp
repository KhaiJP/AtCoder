#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[200010];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> A[i];

  dsu uf(200001);
  int answer = 0;

  rep(i, 0, N/2)if(!uf.same(A[i], A[(N-1) - i])){
    uf.merge(A[i], A[(N-1) - i]);
    ++answer;
  }

  cout << answer << endl;
  return 0;
}