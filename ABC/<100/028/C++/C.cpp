#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[6], ans[30];

int main(){
  rep(i, 0, 5) cin >> A[i];
  
  int tot = 0; rep(i, 0, 5) tot += A[i];
  int pos = 0;
  rep(i, 0, 4)rep(j, i + 1, 5){
    ans[pos] = tot - (A[i] + A[j]);
    ++pos;
  }sort(ans, ans+pos, greater<int>());

  cout << ans[2] << endl;
  return 0;
}