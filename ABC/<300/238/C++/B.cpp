#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// where cuts are done
bool CUT[361];

int main(){
  int N; cin >> N;
  // 0 = 360 are always cut
  CUT[0] = true, CUT[360] = true;

  int prev = 0;
  rep(i, 0, N){
    int A; cin >> A;
    prev = (prev + A) % 360;
    CUT[prev] = true;
  }

  int answer = 0;
  prev = 0;
  rep(i, 1, 361){
    if(!CUT[i]) continue;
    answer = max(answer, i - prev);
    prev = i;
  }

  cout << answer << endl;
  return 0;
}