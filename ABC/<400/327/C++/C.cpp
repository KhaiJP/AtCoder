#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> R[10], C[10], G[10];
int A[10][10];

int main(){
  rep(i, 0, 9)rep(j, 0, 9) cin >> A[i][j];
  rep(i, 0, 9)rep(j, 0, 9){
    R[i].insert(A[i][j]);
    C[j].insert(A[i][j]);
    G[3*(i/3)+j/3].insert(A[i][j]);
  }
  bool flag = true;
  rep(i, 0, 9){
    flag = flag && (int)R[i].size() == 9;
    flag = flag && (int)C[i].size() == 9;
    flag = flag && (int)G[i].size() == 9;
  }

  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}