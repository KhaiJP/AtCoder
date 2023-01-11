#include<iostream>
#include<set>
using namespace std;
#define rep(i,s,t) for(int i=(s); i<(t); ++i)

int main(){
  int N; cin >> N;
  set<int> KagamiMochi;
  rep(i,0,N){
    int d; cin >> d;
    KagamiMochi.insert(d);
  }
  cout << KagamiMochi.size() << endl;
  return 0;
}