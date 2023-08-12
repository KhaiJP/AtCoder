#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, a[110];

int main(){
  cin >> N;
  rep(i, 0, N) cin >> a[i];
  int answer = 1e9;
  rep(y, -100, 101){
    int tmp = 0;
    rep(i, 0, N) tmp += (a[i] - y) * (a[i] - y);
    answer = min(answer, tmp);
  }

  cout << answer << endl;
}