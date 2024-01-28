#include<iostream>
using namespace std;

bool f_head, f_body = true;
int N;
string S;

int main(){
  cin >> S;
  N = S.size();

  f_head = isupper(S[0]);
  for(int i = 1; i < N; ++i) f_body = f_body && islower(S[i]);

  cout << (f_head && f_body ? "Yes" : "No") << endl;
  return 0;
}