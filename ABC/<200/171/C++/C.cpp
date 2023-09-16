#include<iostream>
#include<stack>
using namespace std;

int main(){
  int64_t N; cin >> N;
  
  stack<char> answer;
  while(N){
    --N;
    answer.push(N%26+'a');
    N /= 26;
  }
  
  while(answer.size()){
    cout << answer.top();
    answer.pop();
  }cout << endl;
  return 0;
}