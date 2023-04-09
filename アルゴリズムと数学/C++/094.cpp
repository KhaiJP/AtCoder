#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define MAX 1000000000
int B[110];

int main(){
  int N; cin >> N;
  rep(i, 1, N) cin >> B[i]; 
  B[0] = MAX, B[N] = MAX;

  int answer = 0;
  rep(i, 1, N+1) answer += min(B[i-1], B[i]);

  cout << answer << endl;
  return 0;
}