#include<iostream>
#include<iomanip>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[2][11], K, rest[11];
double den, neu;
ll score[2];

ll powten(int pow){
  ll ret = 1;
  while(pow--) ret *= 10;
  return ret;
}

void calculate_scores(){
  score[0] = 0, score[1] = 0;
  rep(i, 1, 10){
    score[0] += i * powten(A[0][i]);
    score[1] += i * powten(A[1][i]);
  }
}


int main(){
  cin >> K;
  rep(i, 1, 10) rest[i] = K;
  rep(i, 1, 11){
    char c; cin >> c;
    int j = c - '0';
    if(i % 5 == 0) continue;
    ++A[i>5][j];
    --rest[j];
  }

  den = (double)(9*K - 8) * (9*K - 9);
  
  rep(t, 1, 10)rep(a, 1, 10)if(rest[t] && rest[a]){
    ++A[0][t], ++A[1][a];
    calculate_scores();
    if(score[0] > score[1]){
      if(t != a) neu += (double)rest[t] * rest[a];
      else neu += (double)rest[t] * (rest[a] - 1);
    }
    --A[0][t], --A[1][a];
  }

  cout << fixed << setprecision(9) << neu / den << endl;
  return 0;
}
