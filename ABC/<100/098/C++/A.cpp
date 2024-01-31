#include<iostream>
#include<queue>
using namespace std;

int main(){
  int A, B; cin >> A >> B;
  priority_queue<int> q;
  q.push(A+B), q.push(A-B), q.push(A*B);
  cout << q.top() << endl;
  return 0;
}