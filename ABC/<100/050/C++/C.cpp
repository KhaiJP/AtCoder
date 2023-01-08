#include<iostream>
#include<vector>
using namespace std;
#define rep(i,s,t) for(int i = (s); i < (t); ++i)
const int MOD = 1000000000+7;

int main(){
  int N; cin >> N;
  vector<int> P(N+1, 0);
  
  int mid = N/2 + N%2;
  rep(i,1,N+1){
    int A; cin >> A;
    ++P[mid - A/2];
  }

  int answer = 1;
  rep(i,1,mid) answer = (answer*(P[i]==2 ? 2 : 0))%MOD;
  if(N%2 == 1 && P[mid] != 1) answer *= 0;
  if(N%2 == 0) answer = (answer*2)%MOD;
  cout << answer << endl;

  return 0;
}