#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A[100010];

int main(){
  int N; cin >> N;
  rep(i, 0, 3*N){
    int a; cin >> a;
    ++A[a];
    if(A[a] == 2) cout << a << ' ';
  }
  cout << endl;
  return 0;
}