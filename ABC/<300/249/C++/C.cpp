#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define repc(c) for(char c = 'a'; c != 'z'+1; ++c)
string S[20];

int main(){
  int N, K; cin >> N >> K;
  rep(i, 0, N) cin >> S[i];

  int m = 1<<N;
  int answer = 0;
  rep(j, 0, m){
    int num_good_c = 0;

    repc(c){
      int num_c_in_S = 0;
      rep(i, 0, N)if( ( j & 1<<i ) > 0 ) num_c_in_S += S[i].find(c) != string::npos;
      num_good_c += num_c_in_S == K;
    }

    answer = max(answer, num_good_c);
  }

  cout << answer << endl;
  return 0;
}