#include<iostream>
#include<set>
#include<atcoder/all>
using namespace std;
using UF = atcoder::dsu;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// ∃i,j s.t. (xi,yi) = (a, b) and (xj, yj) = (b, c) => a and c are swappable.
// let us consider a graph with 2N nodes; let 0 <= u < N indicate the indeces of p
// and N <= u < 2N indicate the values of p. (here p[] is replaced by 0-indexed array)
// originally ∀i s.t. 0<=u<N are connected to p[u]+N, and xi and yi for 0<=i<M are connected.
// iff i and N+i are connected, then we can make p[i] = i. -> use UnionFind

int N, M, answer, p[100010];

int main(){
  cin >> N >> M;
  
  UF uf(2*N);
  rep(i, 0, N){
    cin >> p[i];
    --p[i]; // making 0-indexed
    uf.merge(i, p[i] + N);
  }

  rep(i, 0, M){
    int x, y; cin >> x >> y; --x, --y;
    uf.merge(x, y);
  }

  for(auto g : uf.groups()){
    set<int> idx, val;
    for(auto u : g){
      if(u < N) idx.insert(u);
      else      val.insert(u);
    }
    for(auto u : idx) answer += val.count(u+N);
  }

  cout << answer << endl;
  return 0;
}