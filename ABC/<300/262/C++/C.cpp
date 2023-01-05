#include<iostream>
#include<vector>
using namespace std;
typedef int64_t ll;
#define rep(i,s,t) for(int i=(s); i<(t); ++i)

int main(){
  int N; cin >> N;
  vector<ll> A(N+1);
  ll same = 0;
  rep(i,1,N+1){
    cin >> A[i];
    if(A[i] == i) same += 1;
  }
  ll answer = same*(same-1)/2;
  rep(i,1,N+1){
    if(A[i] <= i) continue;
    bool flag = min(A[i], A[A[i]]) == i && max(A[i], A[A[i]]) == A[i];
    if(flag) answer += 1;
  }
  cout << answer << endl;
  return 0;
}