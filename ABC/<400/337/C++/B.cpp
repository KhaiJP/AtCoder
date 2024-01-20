#include<iostream>
#include<regex>
using namespace std;

string S;
regex re{R"(A*B*C*)"};

int main(){
  cin >> S;
  cout << (regex_match(S, re) ? "Yes" : "No") << endl;
  return 0;
}