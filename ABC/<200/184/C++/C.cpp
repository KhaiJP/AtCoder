#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
  if(r1 == r2 && c1 == c2) cout << 0 << endl;
  else if((abs(r1 - r2) + abs(c1 - c2)) <= 3) cout << 1 << endl;
  else if(r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2) cout << 1 << endl;
  else{
    if((r1 + c1) % 2 == (r2 + c2) % 2) cout << 2 << endl;
    else if(abs(r1 - r2) + abs(c1 - c2) <= 6) cout << 2 << endl;
    else{
      rep(r, r1 - 3, r1 + 4)rep(c, c1 - 3, c1 + 4){
        if((abs(r - r1) + abs(c - c1) <= 3)){
          if(r + c == r2 + c2 || r - c == r2 - c2){
            cout << 2 << endl;
            return 0;
          }
        }
      }
      cout << 3 << endl;
    }
  }

  return 0;
}