#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

const int INF = 1000000007;
int A[11][11];
int order[10];
int N;
set<pair<int, int>> rumour;

bool is_valid_order(){
  rep(i, 0, N-1){
    int &pre = order[i], &next = order[i+1];
    if( rumour.count( { min(pre, next), max(pre, next) } ) == 1 ){
      return false;
    }
  }
  return true;
}

int main(){
  cin >> N;
  rep(i, 0, N)rep(j, 0, N) cin >> A[i][j];

  // set rumours
  int M; cin >> M;
  rep(m, 0, M){
    int X, Y; cin >> X >> Y; --X, --Y;
    rumour.insert({X, Y});
  }

  // brute-force
  rep(i, 0, N) order[i] = i;
  int answer = INF;
  do{
    int goal_time = 0;
    if(!is_valid_order()) continue;

    rep(j, 0, N){
      goal_time += A[order[j]][j];
    }

    answer = min(answer, goal_time);
  }while(next_permutation(order, order+N));
  
  cout << (answer == INF ? -1 : answer) << endl;
  return 0;
}