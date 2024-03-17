#include<iostream>
using namespace std;

int main(){
  int64_t X; cin >> X;
  if(X >= 0){
    cout << (X + 9) / 10 << endl;
  }else{
    cout << X / 10 << endl;
  }
  
  return 0;
}