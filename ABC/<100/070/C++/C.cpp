#include<iostream>
#include<numeric>
using namespace std;

int main(){
  int32_t N; cin >> N;
  int64_t T, lm; cin >> lm;
  for(int i=1; i<N; ++i){
    cin >> T;
    lm = lcm(lm, T);
  }
  cout << lm << endl;
  return 0;
}