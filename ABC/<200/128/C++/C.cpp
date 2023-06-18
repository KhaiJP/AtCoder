#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> connected_switches[11];
int p[11];
int N, M;
bool is_on[11];

bool isBright(int index){
  int num_switch_on = 0;
  for(auto switch_id : connected_switches[index]){
    num_switch_on += is_on[switch_id];
  }
  
  return num_switch_on%2 == p[index];
}

int main(){
  cin >>N >> M;
  rep(i, 0, M){
    int k; cin >> k;
    rep(j, 0, k){
      int s; cin >> s;
      --s;
      connected_switches[i].push_back(s);
    }
  }
  
  rep(i, 0, M) cin >> p[i];
  
  int answer = 0;
  rep(i, 0, 1<<N){
    int switch_info = i;
    rep(j, 0, N){
      is_on[j] = switch_info % 2;
      switch_info /= 2;
    }
    bool all_on = true;
    rep(j, 0, M) all_on = all_on && isBright(j);
    answer += all_on;
  }
  
  cout << answer << endl;
  return 0;
}
    