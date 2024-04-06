#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, X[110], Y[110];

int main(){
  cin >> N;
  rep(i, 0, N) cin >> X[i] >> Y[i];
  rep(i, 0, N){
    int d_squared = 0, answer = 0;
    rep(j, 0, N){
      int tmp_squared = (X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]);
      if(d_squared < tmp_squared){
        d_squared = tmp_squared;
        answer = j+1;
      }
    }
    cout << answer << endl;
  }

  return 0;
}