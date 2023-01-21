#include<iostream>
#include<string>
using namespace std;

int main(){
  int N; cin >> N;
  string S; cin >> S;
  
  string answer = "";
  int index = 0;
  while(index < N){
    if(S[index] == 'n' && (index < N-1 && S[index+1] == 'a')){
      answer += "nya";
      index += 2;
    }else{
      answer += S[index];
      ++index;
    }
  }
  cout << answer << endl;
  return 0;
}