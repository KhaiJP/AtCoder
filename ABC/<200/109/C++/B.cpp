#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  vector<string> W(N);
  set<string> already;
  rep(i,0,N){
    cin >> W[i];
    if(already.count(W[i]) == 1){cout << "No" << endl; return 0;}
    already.insert(W[i]);
  }
  rep(i,0,N-1)if(W[i].back() != W[i+1].front()){cout << "No" << endl; return 0;};
  cout << "Yes" << endl;
  return 0;
}