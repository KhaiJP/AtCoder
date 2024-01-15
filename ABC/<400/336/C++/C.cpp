#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

ll N;
string answer, s = "02468";
vector<ll> v;

int main(){
  cin >> N;
  --N;
  if(N == 0){
    cout << 0 << endl;
    return 0;
  }

  while(N){
    v.push_back(N%5);
    N /= 5;
  }
  for(auto c : v){
    answer += s[c];
  }
  reverse(answer.begin(), answer.end());
  cout << answer << endl;
  return 0;
}