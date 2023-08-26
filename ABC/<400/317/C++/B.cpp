#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, A[110];

int main(){
  cin >> N;
  rep(i, 0, N) cin >> A[i];
  sort(A, A+N);

  rep(i, 0, N-1)if(A[i+1] != A[i] + 1){
    cout << A[i] + 1 << endl;
    return 0;
  }
}