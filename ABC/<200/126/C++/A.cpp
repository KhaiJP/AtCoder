#include<iostream>
using namespace std;

int main(){
  int N, K; cin >> N >> K;
  string S; cin >> S;
  S[K-1] = (char)tolower(S[K-1]);
  cout << S << endl;
  return 0;
}