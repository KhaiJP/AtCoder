#include<iostream>
#include<deque>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

deque<char> q[200010];
int main(){
  int k = 0;
  int N; cin >> N;
  rep(i, 0, N){
    char c; cin >> c;
    if(c == ')' && k > 0){
      q[k].clear();
      --k;
    }else{
      k += c == '(';
      q[k].push_back(c);
    }
  }

  rep(i, 0, k+1){
    while(!q[i].empty()){
      cout << q[i].front();
      q[i].pop_front();
    }
  }
  cout << endl;
  return 0;
}