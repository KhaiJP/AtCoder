#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll cnt[11][11];

int get_head_of(int X){
  while(X/10) X /= 10;
  return X;
}

int main(){
  int N; cin >> N;

  rep(A, 1, N+1){
    int A_tail = A % 10;
    int A_head = get_head_of(A);
    ++cnt[A_head][A_tail];
  }

  ll answer = 0;
  rep(A_head, 1, 10)rep(A_tail, 1, 10){
    answer += cnt[A_head][A_tail] * cnt[A_tail][A_head];
  }
  
  cout << answer << endl;
  return 0;
}