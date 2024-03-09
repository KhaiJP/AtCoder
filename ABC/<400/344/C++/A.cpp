#include<iostream>
using namespace std;

bool to_show = true;
string S;

int main(){
  cin >> S;
  for(auto c : S){
    if(c == '|'){
      to_show = !to_show;
    }
    else if(to_show){
      cout << c;
    }
  }
  cout << endl;
  return 0;
}