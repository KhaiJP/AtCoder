#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[100], P[110][15];

int andsum(int a, int b){
  // say a = 25 = 0b011001 and b = 51 = 0b110011,
  // this function returns 0*1 + 1*1 + 1*0 + 0*0 + 0*1 + 1*1 = 2
  int c = a & b;
  int and_sum = 0;
  while(c){
    and_sum += c & 1;
    c >>= 1;
  }
  return and_sum;  
}

int main(){
  int N; cin >> N;
  rep(i, 0, N)rep(j, 0, 10){
    int f; cin >> f;
    F[i] += f << j;
  }
  rep(i, 0, N)rep(j, 0, 11) cin >> P[i][j];

  int answer = -1000000007;
  // joisino must open at least once
  rep(schedule, 1, 1 << 10){
    int candidate = 0;

    // andsum(F[j], schedule) gives # of coinsidences
    // that open joisino and shop j open.
    rep(j, 0, N) candidate += P[j][andsum(F[j], schedule)];
    answer = max(answer, candidate);
  }
  cout << answer << endl;
  return 0;
}
