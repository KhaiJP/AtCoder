#include<iostream>
#include<string>
using namespace std;
typedef int64_t ll;
const ll pInf32 =  1000000000+7;

int main(){
  ll N; cin >> N;
  string S[2]; cin >> S[0] >> S[1];
  // domino sit vertically -> type 0, horizontally -> type 1.
  ll ans = 1, pos = 0, prev_type = -1;
  while(pos < N){
    // if current type == 0
    if(S[0][pos] == S[1][pos]){
      if(prev_type == -1) ans *= 3;
      if(prev_type ==  0) ans *= 2;
      if(prev_type ==  1) ans *= 1;
      ++pos;
      prev_type = 0;
    }else{ // if current type == 1
      if(prev_type == -1) ans *= 6;
      if(prev_type ==  0) ans *= 2;
      if(prev_type ==  1) ans *= 3;
      pos += 2;
      prev_type = 1;
    }
    ans = ans%pInf32;
  }
  cout << ans << endl;
  return 0;
}