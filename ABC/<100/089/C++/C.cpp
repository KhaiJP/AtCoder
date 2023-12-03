#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string r = "MARCH";
map<char, int> m;
ll a[] = {0, 0, 1, 1, 1}, N, answer;

int main(){
  cin >> N;
  rep(i, 0, N){
    string S; cin >> S;
    if(r.find(S[0]) != string::npos){
      ++m[S[0]];
    }
  }

  do{
    ll tmp = 1;
    rep(i, 0, 5)if(a[i]==1) tmp *= m[r[i]];
    answer += tmp;
  }while(next_permutation(a, a+5));

  cout << answer << endl;
  return 0;
}