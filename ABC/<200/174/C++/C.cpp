#include<iostream>
using namespace std;

bool visited[1000010];

int main(){
  int N; cin >> N;
  int residual = 7%N, answer = 1;
  
  while(true){
    if(residual == 0){
      cout << answer << endl;
      return 0;
    }else if(visited[residual]){
      cout << -1 << endl;
      return 0;
    }
    ++answer;
    visited[residual] = true;
    residual = (10 * residual + 7) % N;
  }
}