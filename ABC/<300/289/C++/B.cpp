#include<iostream>
#include<set>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int ans[101];
set<int> re;

int main(){
  int N, M; cin >> N >> M;
  rep(i,1,M+1){
    int a; cin >> a;
    re.insert(a);
  }

  // used as a stack
  deque<int> dq;
  rep(i,1,N+1){
    dq.push_back(i);
    if(re.count(i) == 1) continue;
    while(!dq.empty()){
      cout << dq.back() << ' ';
      dq.pop_back();
    }
  }
  cout << endl;
  return 0;
}