#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<pair<int, int>> BA;
int N, answer, ct;

int main(){
  cin >> N;
  rep(i, 0, N){
    int A, B; cin >> A >> B;
    BA.insert({B, A});
  }

  for(auto ba : BA){
    int b = ba.first, a = ba.second;
    if(ct <= a){
      ++answer;
      ct = b;
    }
  }

  cout << answer << endl;
  return 0;
}