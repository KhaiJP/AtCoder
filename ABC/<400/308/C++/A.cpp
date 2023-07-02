#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  bool flag = true;
  int pre = -1;
  rep(i, 0, 8){
    int s; cin >> s;
    flag = flag && s >= pre;
    flag = flag && s>=100 && s<=675;
    flag = flag && s%25 == 0;
    pre = s;
  }

  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}