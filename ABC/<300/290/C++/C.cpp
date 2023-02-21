#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  set<int> S;
  int N, K; cin >> N >> K;
  rep(i, 0, N){
    int a; cin >> a;
    if( a < K ) S.insert(a);
  }
  int answer = 0;
  auto itr = S.begin();
  while( itr != S.end() ){
    if(*itr == answer) ++answer;
    ++itr;
  }

  cout << answer << endl;
  return 0;
}