#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define yes "Yes"
#define noo "No"

bool Tkhs[8][8], Aoki[8][8];
int V[8];

int main(){
  int N, M; cin >> N >> M;
  // V : permutation vec. "V[i] = j" => i is replaced by j.
  rep(i,0,N) V[i] = i;

  // set edges
  rep(i, 0, M){
    int A, B; cin >> A >> B;
    --A, --B;
    Tkhs[A][B] = Tkhs[B][A] = true;
  }
  rep(i, 0, M){
    int C, D; cin >> C >> D;
    --C, --D;
    Aoki[C][D] = Aoki[D][C] = true;
  }

  // main part
  do{
    bool checker = true;
    rep(i, 0, N)rep(j, 0, N) checker = checker && Tkhs[i][j] == Aoki[V[i]][V[j]];
    if(checker){
      cout << yes << endl;
      return 0;
    }
  }while( next_permutation(V, V + N)  );

  cout << noo << endl;
  return 0;
}