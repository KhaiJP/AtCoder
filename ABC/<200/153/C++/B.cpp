#include<iostream>
using namespace std;

int H, N, total;

int main(){
  cin >> H >> N;
  while(N--){
    int A; cin >> A;
    total += A;
  }
  cout << (H <= total ? "Yes" : "No") << endl;
  return 0;
}