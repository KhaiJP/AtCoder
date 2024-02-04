#include<iostream>
using namespace std;
using ll = int64_t;

ll N, answer;

int main(){
  cin >> N;
  while(N--){
    ll A; cin >> A;
    answer = max(answer + A, (ll)0);
  }
  cout << answer << endl;
  return 0;
}