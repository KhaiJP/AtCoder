#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int answer, N;

int main(){
  cin >> N;
  while(N%2 == 0){
    ++answer;
    N >>= 1;
  }
  cout << answer << endl;
  return 0;
}