#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int n, c, a[110], answer = 1e9;

int main(){
  cin >> n >> c;
  rep(i, 0, n) cin >> a[i];
  
  rep(col_even, 1, 11)rep(col_odd, 1, 11)if(col_even != col_odd){
    int tmp = 0;
    rep(i, 0, n){
      if(i%2 == 0 && a[i] != col_even) tmp += c;
      if(i%2 == 1 && a[i] != col_odd)  tmp += c;
    }
    answer = min(answer, tmp);
  }

  cout << answer << endl;
  return 0;
}