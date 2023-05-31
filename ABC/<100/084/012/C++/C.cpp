#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int tot = 0;
  rep(i, 1, 10)rep(j, 1, 10) tot += i * j;

  int N; cin >> N;
  rep(i, 1, 10)if((tot - N) % i == 0 && (tot - N) / i < 10){
    cout << i << " x " << (tot - N) / i << endl;
  }
  return 0;
}