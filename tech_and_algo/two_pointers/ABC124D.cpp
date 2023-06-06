#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, K; cin >> N >> K;
  string S; cin >> S;

  // encode S in run-length encoding
  vector<pair<char, int>> rls;
  char pre = S[0];
  int len = 1;
  rep(i, 1, N){
    if(S[i] == pre) ++len;
    else{
      rls.push_back({pre, len});
      pre = S[i];
      len = 1;
    }
  } rls.push_back({pre, len});

  // find the maximum length
  int n = rls.size();
  int answer = 0, sm = 0, k = 0, l = 0;
  rep(r, 0, n){
    sm += rls[r].second;
    if(rls[r].first == '0') ++k;

    while(K < k){
      sm -= rls[l].second;
      if(rls[l].first == '0') --k;
      ++l;
    }

    answer = max(answer, sm);
  }

  cout << answer << endl;
  return 0;
}