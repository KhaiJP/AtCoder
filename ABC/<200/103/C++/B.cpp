#include<iostream>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int main(){
  string S, T; cin >> S >> T;
  deque<char> s, t;
  for(char c : S) s.push_back(c);
  for(char c : T) t.push_back(c);
  rep(i, 0, 100){
    if(s == t){
      cout << "Yes" << endl;
      return 0;
    }
    s.push_front(s.back());
    s.pop_back();
  }

  cout << "No" << endl;
  return 0;
}