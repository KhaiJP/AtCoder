#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = int64_t;

ll N, r, ll1 = 1;
string S;

int main(){
  cin >> S >> N;
  reverse(S.begin(), S.end());
  
  for(int i = 0; i < S.size(); ++i)if(S[i] == '1') r += (ll1 << i);
  for(int i = S.size()-1; i >= 0; --i)if(S[i] == '?' && r + (ll1 << i) <= N) r += (ll1 << i);
  cout << (r <= N ? r : -1) << endl;
  return 0;
}