#include<iostream>
#include<iterator>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<int, int> S[2010];
int main(){
  int N; cin >> N;
  
  unordered_map<int, unordered_set<int>> um;
  rep(i, 0, N){
    int x, y; cin >> x >> y;
    S[i] = {x, y};
    um[x].insert(y);
  }sort(S, S+N);

  // the bottom-left point is (x1, y1) and counts up with counterclockwise
  int answer = 0;
  rep(i, 0, N-2){
    int &x1 = S[i].first,  &y1 = S[i].second;

    rep(j, i+1, N-1){
      int &x4 = S[j].first,  &y4 = S[j].second;
      if(x1 != x4) continue;

      rep(k, j+1, N){
        int &x2 = S[k].first,  &y2 = S[k].second;
        if(y1 != y2) continue;
        
        answer += um[x2].count(y4) == 1;
      }
    }
  }
  cout << answer << endl;
  return 0;
}