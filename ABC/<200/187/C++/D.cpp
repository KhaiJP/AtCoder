#include<iostream>
#include<queue>
using namespace std;
typedef int64_t ll;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  ll sumA = 0, sumB = 0;
  priority_queue<ll> pq;
  rep(i,0,N){
    ll A, B; cin >> A >> B;
    sumA += A;
    pq.push(2*A+B);
  }

  int answer = 0;
  while(sumA >= sumB){
    sumB += pq.top(); pq.pop();
    ++answer;
  }
  cout << answer << endl;
  return 0;
}