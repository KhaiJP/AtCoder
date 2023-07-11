#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int main(){
  int Q; cin >> Q;
  
  deque<int> q;
  priority_queue<int> pq;
  
  while(Q--){
    int e; cin >> e;
    if(e == 1){
      int x; cin >> x;
      q.push_back(x);
    }

    if(e == 2){
      if(pq.size()){
        cout << -pq.top() << endl;
        pq.pop();
      }
      else{
        cout << q.front() << endl;
        q.pop_front();
      }
    }

    if(e == 3){
       while(q.size()){
        pq.push(-q.front());
        q.pop_front();
       }
    }
  }

  return 0;
}