#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string S[110];
int A[110];

int main(){
  int N; cin >> N;
  rep(i, 0, N) cin >> S[i] >> A[i];
  int mini = 1000000000, mini_id;
  rep(i, 0, N)if(A[i] < mini){
    mini = A[i];
    mini_id = i;
  }

  rep(i, 0, N) cout << S[(mini_id + i) % N] << endl;

  return 0;
}