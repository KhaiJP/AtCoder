#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool is_326_like(int n){
  int n1 = n%10; n /= 10;
  int n2 = n%10; n /= 10;
  int n3 = n;
  return n3 * n2 == n1;
}

int main(){
  int N; cin >> N;
  rep(i, N, 1000)if(is_326_like(i)){
    cout << i << endl;
    return 0;
  }
}