#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string S, r = "WWBWBWBWW";
string ans[] = {"Mi", "_", "Re", "_", "Do", "Si", "_", "La", "_", "So", "_", "Fa", "_"};

int main(){
  cin >> S;
  int k = S.find(r);
  cout << ans[k] << endl;
  return 0;
}