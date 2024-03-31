#include<iostream>
using namespace std;

int main(){
  int N, K; cin >> N >> K;
  while(N--){
    int A; cin >> A;
    if(A%K == 0) cout << A/K << endl; 
  }

  return 0;
}
