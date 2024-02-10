#include<iostream>
using namespace std;

int main(){
  int A, B, D; cin >> A >> B >> D;
  for(int i = A; i <= B; i += D){
    cout << i << ' ';
  }cout << endl;
  return 0;
}