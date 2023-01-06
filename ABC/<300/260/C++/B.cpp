#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int> pr;
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

const int nInf32 = -1000000000;

int main(){
  int N, X, Y, Z; cin >> N >> X >> Y >> Z;
  set<int> passed;
  vector<pr> math(N), eng(N), tot(N);
  rep(i,0,N){
    int A; cin >> A;
    math[i] = {A, -i};
  }
  rep(i,0,N){
    int B; cin >> B;
    eng[i] = {B,-i};
  }
  rep(i,0,N) tot[i] = {math[i].first + eng[i].first, -i};

  sort(math.rbegin(), math.rend());
  rep(i, 0, X){
    int passer = -math[i].second; 
    passed.insert(passer+1);
    eng[passer].first = nInf32;
    tot[passer].first = nInf32;
  }
  sort(eng.rbegin(), eng.rend());
  rep(i, 0, Y){
    int passer = -eng[i].second; 
    passed.insert(passer+1);
    tot[passer].first = nInf32;
  }
  sort(tot.rbegin(), tot.rend());
  rep(i,0,Z){
    int passer = -tot[i].second;
    passed.insert(passer+1);
  }
  for(auto passer:passed) cout << passer << '\n';
  cout << endl;
  return 0;
}