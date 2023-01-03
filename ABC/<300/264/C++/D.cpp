#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main(){
  string S; cin >> S;
  
  int N = 7;
  map<char, int> m;
  m['a'] = 0; m['t'] = 1; m['c'] = 2; m['o'] = 3; m['d'] = 4; m['e'] = 5; m['r'] = 6;
  vector<int> BIT(N, 0);

  int num_inversion = 0;
  for(int i=0; i<N; ++i){
    int &n = m[S[i]];
    BIT[n] += 1;
    int tmp = 0;
    for(int j = 0; j<=n; ++j)if(BIT[j]==1) tmp++;
    num_inversion += (i+1) - tmp;
  }
  cout << num_inversion << endl;
  return 0;
}