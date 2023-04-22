#include<iostream>
#include<map>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<int, int> CR[200010], Ri[200010];
map<int, set< pair< int, int > > > C_Ri;

int main(){
 int N, T; cin >> N >> T;

 rep(i, 0, N) cin >> CR[i].first;
 rep(i,0,N){
  cin >> CR[i].second;
  Ri[i] = {-CR[i].second, i+1};
 }

 rep(i, 0, N){
  int &C = CR[i].first, &R = CR[i].second;
  C_Ri[C].insert({-R, i+1});
 }

  if(C_Ri.count(T) == 1){
    auto &p = *C_Ri[T].begin();
    cout << p.second << endl;
    return 0;
  }

  else{
    int &C1 = CR[0].first;
    auto &p = *C_Ri[C1].begin();
    cout << p.second << endl;
    return 0;
  }
  return 0;
}