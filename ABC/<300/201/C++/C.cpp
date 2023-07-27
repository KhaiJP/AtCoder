#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

bool o[10], x[10];

bool imply(bool a, bool b){
  // returns a -> b which is equivalent to !a || b
  return !a || b;
}

int main(){
  rep(i, 0, 10){
    char c; cin >> c;
    if(c == 'o') o[i] = true;
    if(c == 'x') x[i] = true;
  }

  int answer = 0;
  rep(i, 0, 10000){
    int j = i;
    int used[10];
    rep(k, 0, 10) used[k] = 0;
    rep(k, 0, 4){
      ++used[j % 10];
      j /= 10;
    }

    bool flag = true;
    rep(k, 0, 10){
      bool tmp = imply(o[k], used[k] > 0) && imply(x[k], used[k] == 0);
      flag = flag && tmp;
    }
    
    answer += flag;
  }
  
  cout << answer << endl;
  return 0;
}