#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  rep(i,0,3){
    string c; cin >> c;
    cout << c[i];
  }
  cout << endl;
  return 0;
}