#include<iostream>
#include<string>
using namespace std;
using ll = long long;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll X, answer = 5e18;
int order;

void dfs(string &s, int delta = -100){
  if(s.size() == 0){
    rep(i, 1, 10){
      s += (char)(i + '0');
      dfs(s);
      s.pop_back();
    }
  }
  else if(s.size() == order && stoll(s) >= X){
    answer = min(answer, stoll(s));
  }
  else if(s.size() == order + 1){
    if(s.size() == 19 && s[0] != 1) return ;
    answer = min(answer, stoll(s));
    return ;
  }
  else if(delta == -100){
    rep(i, 0, 10){
      int j = (char)(s.back() - '0');
      s += (char)(i + '0');
      dfs(s, i - j);
      s.pop_back();
    }
  }
  else{
    int j = (char)(s.back() - '0');
    if(0 <= j + delta && j + delta <= 9){
      s += (char)(j + delta + '0');
      dfs(s, delta);
      s.pop_back();
    }else{
      return ;
    }
  }
}

int main(){
  cin >> X;
  
  ll x = X;
  while(x){
    ++order;
    x /= 10;
  }

  string s = "";
  dfs(s);

  cout << answer << endl;
  return 0;
}