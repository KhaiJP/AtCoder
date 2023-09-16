#include<iostream>
using namespace std;

int64_t cnt[100010], N, answer, A, B, C, Q;

int main(){
  cin >> N;
  while(N--){
    cin >> A;
    ++cnt[A];
    answer += A;
  }

  cin >> Q;
  while(Q--){
    cin >> B >> C;
    answer += cnt[B] * (C - B);
    cout << answer << endl;
    cnt[C] += cnt[B];
    cnt[B] = 0;
  }

  return 0;
}