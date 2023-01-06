#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef pair<char, int> pr;

void encode_in_run_length(string &s, vector<pr> &v);

int main(){
  string S, T; cin >> S >> T;
  vector<pr> rl_S, rl_T;
  encode_in_run_length(S, rl_S);
  encode_in_run_length(T, rl_T);
  bool flag = rl_S.size() == rl_T.size();
  int i = 0;
  while(flag){
    if(i == rl_S.size()) break;
    // must be same letter
    bool flag1 = rl_S[i].first == rl_T[i].first;
    // same length is enough
    bool flag2 = rl_S[i].second == rl_T[i].second ;
    // even when lengths differ, if the legth is achievable then it's also ok 
    bool flag3 = rl_S[i].second > 1 && rl_S[i].second <= rl_T[i].second;

    flag = flag && flag1 && (flag2 || flag3);
    i++;
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}

// v must be empty
void encode_in_run_length(string &s, vector<pr> &v){
  int i = 0, delta;
  while(i < s.size()){
    delta = 1;
    while(s[i+delta] == s[i]) delta++;
    v.push_back({s[i], delta});
    i += delta;
  }
}

// // greedy
// int main(){
//   string S, T; cin >> S >> T;
//   int index_s = 0, index_t = 0;
//   while(index_t<T.size()){
//     if(index_s == S.size()){
//       for(int i_t = index_t; i_t<T.size(); i_t++){
//         if(T[i_t] != T[i_t-1]){
//           cout << "No" << endl;
//           return 0;
//         }
//       }
//       cout << "Yes" << endl;
//       return 0;
//     }

//     if(S[index_s] == T[index_t]){
//       index_s++;
//       index_t++;
//       continue;
//     }

//     if(index_t < 2 || T[index_t-1] != T[index_t] || T[index_t-2]!=T[index_t]){
//       cout << "No" << endl;
//       return 0;
//     }else index_t++;
//   }  
//   cout << "Yes" << endl;
//   return 0;
// }