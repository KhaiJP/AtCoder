#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int has_stronger[55];
set<int> saikyo;

int main(){
  int N, M; cin >> N >> M;
  rep(i, 0, M){
    int A, B; cin >> A >> B;
    ++has_stronger[B];
  }

  rep(i, 1, N+1)if(has_stronger[i] == 0) saikyo.insert(i);
  cout << (saikyo.size() > 1 ? -1 : *saikyo.begin()) << endl;
  return 0;
}