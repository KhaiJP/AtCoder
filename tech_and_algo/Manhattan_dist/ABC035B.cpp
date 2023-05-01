#include<iostream>
#include<string>
using namespace std;

int main(){
  string S; cin >> S;
  int T; cin >> T;
  int x = 0, y = 0;

  for(char c : S){
    if(c == 'R') ++x;
    if(c == 'L') --x;
    if(c == 'U') ++y;
    if(c == 'D') --y;
  }

  for(char c : S)if(c == '?'){
    if(T == 1){
      if(x >= 0) ++x;
      else --x;
    }

    if(T == 2){
      if(x > 0) --x;
      else if(x < 0) ++x;
      else{
        if(y >= 0) --y;
        else ++y;
      }
    }
  }

  cout << abs(x) + abs(y) << endl;
  return 0;
}