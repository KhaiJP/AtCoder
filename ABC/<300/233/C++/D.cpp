#include<iostream>
#include<unordered_map>
#define rep(i,t) for(int i=0;i<(t);++i)
using namespace std;

/*
  Consider the prefix sum of A, if pfx[n]-K happens m times in n in 0:n-1,
  then m patterns of subseries that of K are possible.
*/
int main(){
  int64_t N, K; cin >> N >> K;
  unordered_map<int64_t, int64_t> history;
  int64_t pfx = 0;
  int64_t answer = 0;
  rep(i, N){
    history[pfx] += 1;
    int64_t A; cin >> A;
    pfx += A;
    answer += history[pfx-K];
  }
  cout << answer << endl;
  return 0;
}