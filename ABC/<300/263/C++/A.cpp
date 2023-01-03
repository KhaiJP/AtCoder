#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i, s, t) for (int i = (s); i < (t); ++i)
using namespace std;

int main(){
  int n = 5;
  vector<int> P(n); rep(i,0,n) cin >> P[i];
  vector<int> T(n); rep(i,0,n) T[i] = P[i];
  sort(T.begin(), T.end());
  T.erase(unique(T.begin(), T.end()), T.end());
  if(T.size() != 2){
    cout << "No" << endl;
    return 0;
  }
  int c = count(P.begin(), P.end(), T[0]);
  if(c == 2 || c == 3){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}