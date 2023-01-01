#include<iostream>
#include<vector>
#define rep(i,s,t) for(int i=(s); i<(t); ++i)
using namespace std;
typedef pair<int, int> P;

int main(){
  int N, S; cin >> N >> S;
  vector<P> Cards(N+1);
  vector SUM(N+1, vector<bool>(S+1, false) );
  SUM[0][0] = true;
  rep(i, 0, N){
    int a, b; cin >> a >> b;
    Cards[i+1] = P(a,b);
    rep(s, 0, S+1){
      if(SUM[i][s]){
        if(s+a <= S) SUM[i+1][s+a] = true;
        if(s+b <= S) SUM[i+1][s+b] = true;
      }
    }
  }
  if(!SUM[N][S]) cout << "No" << endl;
  else{
    cout << "Yes" << '\n';
    vector<char> answer(N);
    int s = S, n = N;
    while(n!=0){
      if(s-Cards[n].first>=0 && SUM[n-1][s-Cards[n].first]){
        s -= Cards[n].first;
        n -= 1;
        answer[n] = 'H';
      }else{
        s -= Cards[n].second;
        n -= 1;
        answer[n] = 'T';
      }
    }
    rep(n,0,N) cout << answer[n];
    cout << endl;
  }
  return 0;
}