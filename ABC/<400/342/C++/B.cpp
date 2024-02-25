#include<iostream>
using namespace std;

int N, P[110], Q;

int main(){
  cin >> N;
  for(int i = 1; i <= N; ++i) cin >> P[i];

  cin >> Q;
  while(Q--){
    int A, B; cin >> A >> B;
    for(int i = 1; i <= N; ++i)if(P[i] == A || P[i] == B){
      cout << P[i] << endl;
      break;
    }
  }
  
  return 0;
}