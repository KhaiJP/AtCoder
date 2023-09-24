#include<iostream>
#include<stack>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

stack<char> s;

int main(){
  string x; cin >> x;
  // push dummy not to make s empty()
  s.push('d');
  
  for(auto c : x){
    if(c == 'S') s.push(c);
    if(c == 'T'){
      if(s.top() == 'S') s.pop();
      else s.push(c);
    }
  }
  cout << s.size() -1 << endl;
  return 0;
}