#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;

  int l = 1, r = N;
  rep(_, 0, 20){
    int mid = (l + r) / 2;
    cout << '?' << ' ' << mid << '\n';
    int reply; cin >> reply;

    if(reply == 0){
      l = mid;
    }else{
      r = mid;
    }

    if(r == l + 1){
      cout << '!' << ' ' << l << endl;
      return 0;
    }
  }
  return 0;
}