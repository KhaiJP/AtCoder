#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i, s , t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  double answer = 0;
  rep(i, 0, N){
    double current = 0;
    rep(j, 1, 7) current += max((double)j, answer);
    answer = current / 6;
  }
  cout << fixed << setprecision(9) << answer << endl;
  return 0;
}