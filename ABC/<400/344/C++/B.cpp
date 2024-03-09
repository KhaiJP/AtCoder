#include<iostream>
#include<stack>
using namespace std;

stack<int> s;

int main(){
  while(true){
    int A; cin >> A;
    s.push(A);
    if(A == 0){
      while(s.size()){
        cout << s.top() << endl;
        s.pop();
      }
      return 0;
    }
  }
}