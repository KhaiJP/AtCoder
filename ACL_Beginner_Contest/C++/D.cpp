#include<iostream>
#include<vector>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int op(int a, int b){
  return max(a, b);
}

int e(){
  return 0;
}

int main(){
  int N, K; cin >> N >> K;
  
  vector<int> A(N);
  rep(i, 0, N) cin >> A[i];

  segtree<int, op, e> seg(300001);

  for(int a : A){
    int l = max(a - K, 0),   r = min(a + K + 1, 300001);

    int mx = seg.prod(l, r);
    seg.set(a, mx+1);
  }

  cout << seg.all_prod() << endl;
  return 0;
}