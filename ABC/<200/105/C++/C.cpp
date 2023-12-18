#include<iostream>
#include<stack>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)


int main(){
  ll N; cin >> N;
  
  stack<int> s;
  while(N != 0){
    s.push(N%2 != 0);
    N -= N%2 != 0;
    N /= -2;
  }
  
  if(s.size())while(s.size()){
    cout << s.top();
    s.pop();
  }else{
    cout << 0;
  }
  cout << endl;
  return 0;
}