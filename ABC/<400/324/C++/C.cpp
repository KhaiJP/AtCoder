#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, answer;
string T, S;
bool canbe[500010];

int main(){
  cin >> N >> T;
  int t = T.size();

  rep(i, 0, N){
    cin >> S;
    int s = S.size();
    
    if(abs(t-s) > 1) continue;

    if(t == s){
      int n_diff = 0;
      rep(j, 0, t) n_diff += T[j] != S[j];
      canbe[i] = n_diff <= 1;
    }

    if(s == t + 1){
      int id = -1;
      bool f = true;
      rep(j, 0, t){
        ++id;
        if(S[id] == T[j]) continue;
        if(id == s-1 || S[id+1] != T[j]){
          f = false;
          break;
        }
        ++id;
      }
      canbe[i] = f;
    }

    if(s == t - 1){
      int id = -1;
      bool f = true;
      rep(j, 0, s){
        ++id;
        if(S[j] == T[id]) continue;
        if(id == t-1 || S[j] != T[id+1]){
          f = false;
          break;
        }
        ++id;
      }
      canbe[i] = f;
    }

    answer += canbe[i];
  }

  cout << answer << endl;
  rep(i, 0, N)if(canbe[i]) cout << i + 1 << ' '; cout << endl;
  return 0;
}