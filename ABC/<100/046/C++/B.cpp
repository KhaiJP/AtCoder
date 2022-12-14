#include<iostream>
#include<vector>
#define rep(i,s,n) for(int i=s; i<n; ++i)
using namespace std;

int main(){
  int N, K; cin >> N >> K;
  if(N==1){
    cout << K << endl;
    return 0;
  }
  int16_t power = 2;
  int32_t answer = (K-1)*(K-1);
  while(true){
    if(power*power < N-1){
      answer *= answer;
      power += power;
    } else break;
  }
  while(power!=N-1){
    answer *= K-1;
    power += 1;
  }
  answer *= K;
  cout << answer << endl;
  return 0;
}