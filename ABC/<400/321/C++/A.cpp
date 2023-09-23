#include<iostream>
using namespace std;

int main(){
  string S; cin >> S;
  char pre = '9' + 1;
  for(char current : S){
    if(!(current < pre)){
      cout << "No" << endl;
      return 0;
    }
    pre = current;
  }

  cout << "Yes" << endl;
  return 0;
}