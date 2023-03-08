#include<iostream>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  int m = 0;
  deque<pair<int, int>> dq;
  dq.push_back({0, 0});
  rep(i, 0, N){
    int a; cin >> a;
    ++m;
    
    if(dq.back().first == a) ++dq.back().second;
    else dq.push_back({a, 1});

    if(dq.back().first == dq.back().second){
      m -= dq.back().second;
      dq.pop_back();
    }

    cout << m << '\n';
  }

  cout << endl;
  return 0;
}