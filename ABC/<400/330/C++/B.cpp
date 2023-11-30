#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, L, R;

int main(){
  cin >> N >> L >> R;
  rep(i, 0, N){
    int a; cin >> a;
    if(a < L)      cout << L << ' ';
    else if(a > R) cout << R << ' ';
    else           cout << a << ' ';
  }

  cout << endl;
  return 0;
}