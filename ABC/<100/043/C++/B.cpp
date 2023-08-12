#include<iostream>
#include<string>
using namespace std;

int main(){
  string s; cin >> s;
  int n = s.size();

  string answer = "";
  for(auto c : s){
    if(c == 'B'){
      if(answer.size()) answer.pop_back();
    }else{
      answer += c;
    }
  }

  cout << answer << endl;
  return 0;
}