#include<iostream>
#include<map>
using namespace std;
using ll = int64_t;

ll N, answer, t;
map<char, ll> m;

int main(){
  string S; cin >> S;
  N = S.size();

  for(auto c : S) ++m[c];
  for(auto p : m){
    answer += p.second * (N-p.second);
    if(p.second > 1) t = 1;
  }

  answer = answer / 2 + t;
  cout << answer << endl;
  return 0;
}