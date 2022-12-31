#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> X(N); 
  int m=1, M=100;
  rep(i,0,N){
    cin >> X[i];
    m = X[i] < m ? X[i] : m;
    M = M < X[i] ? X[i] : M;
  }
  int answer = 1e9;
  rep(P,m,M+1){
    int tmp_sum = 0;
    rep(i,0,N) tmp_sum += (P-X[i])*(P-X[i]);
    answer = tmp_sum < answer ? tmp_sum : answer;
  }
  cout << answer << endl;
  return 0;
}