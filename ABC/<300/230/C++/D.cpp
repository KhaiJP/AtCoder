#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<int, int> wall[200010];

int main(){
  int N, D; cin >> N >> D;
  rep(i ,0, N){
    int L, R; cin >> L >> R;
    wall[i] = {R, L};
  }
  
  int answer = 0, x = -D;
  sort(wall, wall+N);
  // greedy
  rep(i, 0, N){
    if(x + D - 1 < wall[i].second){
      ++answer;
      x = wall[i].first;
    }
  }

  cout << answer << endl;
  return 0;
}