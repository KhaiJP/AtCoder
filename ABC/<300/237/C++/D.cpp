#include<iostream>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define rrep(i, s, t) for(int i = (s); i >= (t); --i)

int main(){
  int N; cin >> N;
  string S; cin >> S;
  deque<int> dq;
  dq.push_back(N);
  rrep(i, N-1, 0){
    if(S[i] == 'R') dq.push_front(i);
    if(S[i] == 'L') dq.push_back(i);
  }
  rep(i, 0, N+1){
    cout << dq.front() << ' ';
    dq.pop_front();
  }
  cout << endl;
  return 0;
}