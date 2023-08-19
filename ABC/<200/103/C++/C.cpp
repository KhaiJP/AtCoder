#include<iostream>
using namespace std;

int answer;

int main(){
  int N; cin >> N;
  for(int i = 0; i < N; ++i){
    int a; cin >> a;
    answer += a;
  }
  cout << answer - N << endl;
  return 0;
}