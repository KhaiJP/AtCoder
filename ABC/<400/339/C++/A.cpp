#include<iostream>
using namespace std;

string S, answer;

int main(){
  cin >> S;
  for(auto c : S){
    if(c == '.') answer = "";
    else answer += c;
  }
  cout << answer << endl;
  return 0;
}