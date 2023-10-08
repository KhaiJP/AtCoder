#include<iostream>
#include<queue>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, M, A[110], score[110];
string S[110];

int main(){
  cin >> N >> M;
  rep(i, 0, M) cin >> A[i];
  rep(i, 0, N) cin >> S[i];

  // check solved problems
  rep(i, 0, N)rep(j, 0, M)if(S[i][j] == 'o'){
    score[i] += A[j];
  }
  // add bonus points
  rep(i, 0, N) score[i] += i + 1;

  // solve
  rep(i, 0, N){
    // collect unsolved problem
    priority_queue<int> q;
    rep(j, 0, M)if(S[i][j] == 'x') q.push(A[j]);
    // check the gap between score[i] and the maximum value other than player i
    int m = 0;
    rep(j, 0, N)if(j != i) m = max(m, score[j]);
    int gap = m - score[i];

    // add unsolved problems until the player i gets unique leader
    int answer = 0;
    while(gap >= 0){
      ++answer;
      gap -= q.top();
      q.pop();
    }
    cout << answer << endl;
  }

  return 0;
}