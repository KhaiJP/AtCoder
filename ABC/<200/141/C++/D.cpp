#include<iostream>
#include<queue>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N, M; cin >> N >> M;
  priority_queue<int> q;
  rep(i, 0, N){
    int A; cin >> A;
    q.push(A);
  }

  rep(_, 0, M){
    int a = q.top();
    q.pop();
    a >>= 1;
    q.push(a);
  }

  ll answer = 0;
  while(!q.empty()){
    answer += q.top();
    q.pop();
  }

  cout << answer << endl;
  return 0;
}