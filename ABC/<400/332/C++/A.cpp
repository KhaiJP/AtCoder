#include<iostream>
using namespace std;

int N, S, K, answer;

int main(){
  cin >> N >> S >> K;
  for(int i = 0; i < N; ++i){
    int P, Q; cin >> P >> Q;
    answer += P * Q;
  }
  
  cout << (answer >= S ? answer : answer + K) << endl;
  return 0;
}