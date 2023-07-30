#include<iostream>
#include<string>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string r[] = {"ACE","BDF","CEG","DFA","EGB","FAC","GBD"};

int main(){
  string s; cin >> s;
  
  rep(i, 0, 7)if(s == r[i]){
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
  return 0;
}