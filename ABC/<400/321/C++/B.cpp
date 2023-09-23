#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

vector<int> A;
int N, X;

int main(){
  cin >> N >> X;
  rep(i, 0, N-1){
    int a; cin >> a;
    A.push_back(a);
  }

  rep(next_score, 0, 101){
    vector<int> B = A;
    B.push_back(next_score);
    sort(B.begin(), B.end());

    int total_score = 0;
    rep(i, 1, N-1) total_score += B[i];
    if(total_score >= X){
      cout << next_score << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}