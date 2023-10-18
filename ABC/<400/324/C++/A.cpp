#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, A[110];

int main(){
  cin >> N;
  rep(i, 0, N) cin >> A[i];
  rep(i, 1, N)if(A[i] != A[0]){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}