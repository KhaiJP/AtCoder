#include<iostream>
using namespace std;
using ll = int64_t;

int main(){
  ll H, W; cin >> H >> W;

  if(H == 1 || W == 1){
    cout << 1 << endl;
    return 0;
  }

  cout << H * W / 2 + (H%2 && W%2) << endl;
  return 0;
}