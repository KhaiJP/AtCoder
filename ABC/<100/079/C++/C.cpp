#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  string ABCD; cin >> ABCD;
  int A=ABCD[0]-'0', B=ABCD[1]-'0', C=ABCD[2]-'0', D=ABCD[3]-'0';
  vector<int> op = {1,-1};
  for(auto op1:op)for(auto op2:op)for(auto op3:op){
    if(A + op1*B + op2*C + op3*D == 7 ){
      cout << A << (op1==1 ? '+' : '-') << B << (op2==1 ? '+' : '-') << C << (op3==1 ? '+' : '-') << D << "=7";
      return 0;
    }
  }
}