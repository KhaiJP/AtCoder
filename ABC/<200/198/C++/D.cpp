#include<iostream>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N[5], answer[5], order[5], ch_to_num[30], inf = 1e18, idx[3];
string S[5];
bool used[15];

void set_Ns(){
  for(int i = 0; i < 3; i += 2){
    N[i] = 0;
    for(auto c : S[i]){
      N[i] *= 10;
      N[i] += ch_to_num[c-'a'];
    }
  }
  N[1] = N[2] - N[0];
  return ;
}

bool check_N1(){
  if(N[1] <= 0) return false;
  string N1 = to_string(N[1]), pool = "", &S1 = S[1];
  if((ll)N1.size() != order[1]) return false;

  bool flag = true;
  rep(i, 0, order[1]){
    char c = S1[i];
    ll num = N1[i] - '0', &c_num = ch_to_num[c-'a'];
    if(c_num >= 0){
      flag = flag && num == c_num; 
    }else{
      if(used[num]){
        flag = false;
        break;
      }
      pool += c;
      c_num = num;
      used[num] = true;
    }
  }

  for(auto &c : pool){
    ll &c_num  = ch_to_num[c-'a'];
    used[c_num] = false;
    c_num       = -1;
  }

  return flag;
}

void dfs(){
  if(idx[0] == order[0] && idx[2] == order[2]){
    set_Ns();
    N[1] = N[2] - N[0];
    if(check_N1())rep(i, 0, 3) answer[i] = N[i]; 
    return ;
  }
  
  ll k = (idx[2] < order[2] ? 2 : 0);
  char c = S[k][idx[k]];
  if(ch_to_num[c-'a'] >=0){
    ++idx[k];
    dfs();
    --idx[k];
    return ;
  }
  
  ll b = (idx[k] == 0 ? 1 : 0);
  rep(c_num, b, 10)if(!used[c_num]){
    used[c_num] = true;  ++idx[k]; ch_to_num[c-'a'] = c_num;
    dfs();
    used[c_num] = false; --idx[k]; ch_to_num[c-'a'] = -1;
  }
  return ;
}

int main(){
  rep(i, 0, 3){
    cin >> S[i];
    order[i] = S[i].size();
    answer[i] = inf;
  }
  rep(i, 0, 26) ch_to_num[i] = -1;

  dfs();

  if(answer[0] == inf) cout << "UNSOLVABLE" << endl;
  else    rep(i, 0, 3) cout << answer[i] << endl;
  
  return 0;
}