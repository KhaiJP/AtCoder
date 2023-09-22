#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int cnt[30];
int N, answer, evens, odds;

int main(){
  string S; cin >> S;
  N = S.size();
  for(char c : S) ++cnt[c-'a'];
  rep(c, 0, 26)if(cnt[c] > 0){
    if(cnt[c]&1){
      ++odds;
      evens += (cnt[c] - 1)/2;
    }
    else evens += cnt[c]/2;
  }
  
  cout << (odds == 0 ? N : 2*(evens/odds) + 1) << endl;
  return 0;
}