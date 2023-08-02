#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)
#define chmax(a, b) a = max(a, b)
#define MAX 1000010

int N, answer, imos[MAX];

int main(){
  cin >> N;
  rep(i, 0, N){
    int a, b; cin >> a >> b;
    ++imos[a], --imos[b+1];
  }
  rep(i, 0, MAX) imos[i] += imos[i-1];

  rep(i, 0, MAX) chmax(answer, imos[i]); 
  cout << answer << endl;
  return 0;
}
