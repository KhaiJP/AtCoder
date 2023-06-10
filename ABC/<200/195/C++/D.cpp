#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<int, int> VW[55];
int X[55];

int main(){
  int N, M, Q; cin >> N >> M >> Q;
  rep(i, 0, N) cin >> VW[i].second >> VW[i].first;
  sort(VW, VW+N, greater<pair<int,int>>());
  rep(i, 0, M) cin >> X[i];

  while(Q--){
    int L, R; cin >> L >> R; --L, --R;
    multiset<int> boxes;
    rep(i, 0, M)if(i < L || R < i) boxes.insert(X[i]);
    int answer = 0;
    rep(i, 0, N){
      int &V = VW[i].first, &W = VW[i].second;
      auto itr = boxes.lower_bound(W);
      if(itr != boxes.end()){
        answer += V;
        boxes.erase(itr);
      }
    }

    cout << answer << endl;
  }

  return 0;
}