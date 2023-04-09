#include<iostream>
#include<string>
#include<stack>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// dp[is][it] : the longest common string of s_1:is and t_1:it,
// here x_1:ix is the substring of x; x_1, x_2, ... , x_ix (1-indexed)
// if x is "abcdefg" and ix = 5 then x_1:ix = "abcde"
int dp[3010][3010];

int main(){
  string s, t; cin >> s >> t;

  rep(is, 1, s.size()+1)rep(it, 1, t.size()+1){
    if(s[is-1] == t[it-1]) dp[is][it] = dp[is-1][it-1] + 1;
    else dp[is][it] = max(dp[is-1][it], dp[is][it-1]);
  }
  
  int is = s.size(),     it = t.size();
  stack<char> answer;
  while(is && it){
    if(s[is-1] == t[it-1]){
      // cout << is << ' ' << it << '\n';
      answer.push(s[is-1]);
      --is, --it;
    }
    else if(dp[is-1][it] > dp[is][it-1]) --is;
    else --it;
  }
  
  while(!answer.empty()){
    cout << answer.top();
    answer.pop();
  }

  cout << endl;
  return 0;
}