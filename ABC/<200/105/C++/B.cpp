#include<iostream>
using namespace std;

int main(){
  int N; cin >> N;
  for(int i = 0; ; ++i){
    int n = N - i*7;
    if(n < 0) break;
    if(n % 4 == 0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}