#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, answer, p[11];

int main(){
  cin >> N;
  rep(i, 0, N) cin >> p[i];
  sort(p, p + N);
  rep(i, 0, N - 1) answer += p[i];
  answer += p[N-1]/2;
  cout << answer << endl;
  return 0;
}