#include<iostream>
#include<vector>
#include<deque>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  deque<vector<int>> dq; rep(i,0,M) dq.push_back({i+1});
  
  while(!dq.empty()){
    vector<int> v = dq.front(); dq.pop_front();
    if(v.size() == N){
      for(auto n : v) cout << n << ' ';
      cout << '\n';
    }else{
      rep(n, v.back()+1, M+1){
        vector<int> vv = v; vv.push_back(n);
        dq.push_back(vv);
      }
    }
  }
  cout << endl;
  return 0;
}