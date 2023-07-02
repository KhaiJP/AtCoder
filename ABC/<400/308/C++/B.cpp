#include<iostream>
#include<map>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int idx_to_price[110];

int main(){
  map<string, int> colour_to_num, colour_to_idx;
  int N, M; cin >> N >> M;
  rep(i, 0, N){
    string c; cin >> c;
    ++colour_to_num[c];
  }

  rep(i, 0, M){
    string d; cin >> d;
    colour_to_idx[d] = i+1; 
  }

  rep(i, 0, M+1) cin >> idx_to_price[i];

  int answer = 0;
  for(auto c_n : colour_to_num){
    string colour = c_n.first;
    int num_eat = c_n.second;
    if(colour_to_idx.count(colour)) answer += num_eat * idx_to_price[colour_to_idx[colour]];
    else answer += num_eat * idx_to_price[0];
  }
  cout << answer << endl;
  return 0;
}