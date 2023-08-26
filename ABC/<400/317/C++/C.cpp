#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int W[11][11], answer;

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int A, B, C; cin >> A >> B >> C; --A, --B;
    W[A][B] = W[B][A] = C;
  }

  vector<int> V(N);
  rep(i, 0, N) V[i] = i;
  do{
    int dist = 0;
    rep(i, 0, N-1){
      if(W[V[i]][V[i+1]] == 0) break;
      else dist += W[V[i]][V[i+1]];
    }
    answer = max(answer, dist);
  }while(next_permutation(V.begin(), V.end()));

  cout << answer << endl;
  return 0;
}