#include<iostream>
using namespace std;

string answer = "1";

int main(){
  int N; cin >> N;
  while(N--) answer += "01";
  cout << answer << endl;
  return 0;
}