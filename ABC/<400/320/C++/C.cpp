#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int M, answer = 1e9;
string S[3];
vector<int> v = {0, 1, 2};
set<int> R;

int get_time(char target, int t=0, int k=0){
  while(true){
    if(S[v[k]][t % M] != target) ++t;
    else if(k != 2) return get_time(target, t+1, k+1);
    else return t; 
  }
}

int main(){
  cin >> M;
  for(int i : v) cin >> S[i];

  rep(n, 0, 10){
    char target = '0' + n;
    bool flag = true;
    for(int i : v) flag = flag && S[i].find(target) != string::npos;
    if(flag) R.insert(n);
  }
  
  do{
    rep(n, 0, 10)if(R.count(n) == 1){
      char target = '0' + n;
      answer = min(answer, get_time(target));
    }
  }while(next_permutation(v.begin(), v.end()));

  cout << (answer < 1e9 ? answer : -1) << endl;
  return 0;
}