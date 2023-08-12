#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

string pi = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main(){
  int N; cin >> N;
  cout << "3.";
  rep(i, 0, N) cout << pi[i];
  cout << endl;

  return 0;
}