#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;
typedef pair<int,char> pr;

int main(){
  int N; cin >> N;
  string S; cin >> S;
  vector<pr> People(N);
  int answer = 0;
  rep(i,0,N){
    int W; cin >> W;
    People[i] = {W, S[i]};
    if(S[i] == '1') answer += 1;
  }
  sort(People.begin(), People.end());

  int X = answer;
  rep(i,0,N){
    if(People[i].second == '1') X -= 1;
    else X += 1;
    bool flag = (i == N-1) || (People[i].first != People[i+1].first); 
    if(flag) answer = max(answer, X);
  }
  cout << answer << endl;
  return 0;
}
