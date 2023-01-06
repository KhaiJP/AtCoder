#include<iostream>
#include<vector>
using namespace std;
#define rep(i,s,t) for(int i=(s); i<(t); i++)
int main(){
  int L1, R1, L2, R2; cin >> L1 >> R1 >> L2 >> R2;
  vector<int> colour(101, 0);
  rep(i,L1,R1) colour[i]++;
  rep(i,L2,R2) colour[i]++;
  int answer = 0;
  rep(i,0,101)if(colour[i]==2) answer++;
  cout << answer << endl;
  return 0;
}