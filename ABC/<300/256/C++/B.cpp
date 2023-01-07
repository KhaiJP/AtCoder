#include<iostream>
#include<vector>
using namespace std;
#define rep(i,s,t) for(int i=(s); i<(t); ++i)

// O(N)
int main(){
  int N; cin >> N;
  int answer = N-3;
  vector<int> P(3,0);
  rep(i,0,N){
    int A; cin >> A;
    if(i < N-3) continue;
    rep(j, 0, i-(N-3)+1) P[j] += A;
  }
  rep(i,0,3) if(P[i]>3) ++answer;
  cout << answer << endl;
  return 0;
}

// O(N^2)
// int main(){
//   int N; cin >> N;
//   vector<int> P(N, 0);
//   rep(i,0,N){
//     int A; cin >> A;
//     rep(j,0,i+1) P[j] += A;
//   }
//   int answer = 0; rep(i,0,N)if(P[i]>3) ++answer;
//   cout << answer << endl;
//   return 0;
// }