#include<iostream>
#include<vector>
#include<atcoder/all>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;
using namespace atcoder;

int main(){
  int N, M; cin >> N >> M;
  vector<int> v(N+1, 0);
  dsu uf(N+1);
  rep(i,0,M){
    int A, B; cin >> A >> B;
    // if A and B already belong to the same tree
    // they have already been connected via one or more nodes,
    // which means the additional A-B edge makes the tree have a loop 
    if(uf.same(A,B)){
      cout << "No" << endl;
      return 0;
    }
    uf.merge(A, B);
    v[A] += 1;
    v[B] += 1;
  }
  rep(i,1,N+1) if(v[i]>2){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}