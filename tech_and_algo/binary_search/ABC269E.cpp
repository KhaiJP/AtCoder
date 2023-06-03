#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;

  int A = 1, B = N;
  rep(i, 0, 10){
    cout << "? " << A << ' ' << (A+B)/2 << ' ' << 1 << ' ' << N << endl;
    int T; cin >> T;
    if(T == -1) return 0;

    if(T == (A+B)/2 - A + 1) A = (A+B)/2 + 1;
    else B = (A+B) / 2;
    if(A == B) break;
  }

  int C = 1, D = N;
  rep(i, 0, 10){
    cout << "? " << 1 << ' ' << N << ' ' << C << ' ' << (C+D)/2 << endl;
    int T; cin >> T;
    if(T == -1) return 0;

    if(T == (C+D)/2 - C + 1) C = (C+D)/2 + 1;
    else D = (C+D) / 2;
    if(C == D)break;
  }
  cout << "! " << A << ' ' << C << endl;
  return 0;
}