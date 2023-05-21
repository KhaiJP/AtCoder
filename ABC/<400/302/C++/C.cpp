#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string S[10];
int v[] = {0, 1, 2, 3, 4, 5, 6, 7};

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, N) cin >> S[i];

  // brute-force
  do{
    bool flag = true;
    rep(i, 0, N-1){
      int hamming_d = 0;
      rep(j, 0, M) hamming_d += S[v[i]][j] != S[v[i+1]][j];
      flag = flag && (hamming_d == 1);
    }

    if(flag){
      cout << "Yes" << endl;
      return 0;
    }
  }while(next_permutation(v, v + N));
  
  cout << "No" << endl;
  return 0;
}