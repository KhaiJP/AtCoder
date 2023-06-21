#include<iostream>
using namespace std;
int cnt[10];

int main(){
  string S; cin >> S;
  for(char c : S) ++cnt[c - 'A'];
  for(int i = 0; i < 6; ++i) cout << cnt[i] << ' ';
  cout << endl;
  return 0;
}
