#include<iostream>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string T, S[15];
int N, A, answer;
map<string, int> dp[110];

bool check(string &s, int base){
  if(s.size() + base > T.size()) return false;
  rep(i, 0, (int)s.size())if(s[i] != T[i+base]){
    return false;
  }
  return true;
}

int main(){
  cin >> T >> N;
  dp[0][""] = 0;
  S[0] = "";

  rep(i, 0, N){
    cin >> A;
    rep(j, 1, A+1) cin >> S[j];

    for(auto p : dp[i]){
      string c_str = p.first;
      int base = c_str.size();
      int cost = p.second;

      rep(j, 0, A+1){
        if(!check(S[j], base)) continue;
        string n_str = c_str + S[j];
        int n_cost = cost + (j == 0 ? 0 : 1);

        if(dp[i+1][n_str] == 0){
          dp[i+1][n_str] = n_cost;
        }else{
          dp[i+1][n_str] = min(dp[i+1][n_str], n_cost);
        }
      }
    }
  }

  answer = dp[N][T];
  cout << (answer > 0 ? answer : -1) << endl;

  return 0;
}