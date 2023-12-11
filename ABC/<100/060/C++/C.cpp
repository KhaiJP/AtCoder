#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, T, answer, pre = -1e9;
int main(){
  cin >> N >> T;
  rep(i, 0, N){
    int t; cin >> t;
    answer += T - max(pre + T - t, 0);
    pre = t;
  }
  
  cout << answer << endl;
  return 0;
}